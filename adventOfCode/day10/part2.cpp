#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <functional>

// Estructura de la máquina
struct Machine {
    int id;
    std::vector<long long> joltage_target;  // Vector b (del {...})
    std::vector<std::vector<int>> buttons;  // Matriz A (de los (...))
};

// Parser del archivo de entrada
std::vector<Machine> parse_input(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Machine> machines;
    
    if (!file.is_open()) {
        std::cerr << "ERROR FATAL: No se encuentra " << filename << std::endl;
        exit(1);
    }

    std::string line;
    int id_counter = 1;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        // Buscamos el inicio de los requisitos de voltaje '{'
        size_t brace_start = line.find('{');
        if (brace_start == std::string::npos) continue;

        Machine m;
        m.id = id_counter++;

        std::string buttons_part = line.substr(0, brace_start);
        std::string target_part = line.substr(brace_start);

        // 1. Parsear Target {...}
        for (char &c : target_part) if (c == '{' || c == '}' || c == ',') c = ' ';
        std::stringstream ss_target(target_part);
        long long val;
        while (ss_target >> val) m.joltage_target.push_back(val);

        int num_rows = m.joltage_target.size();

        // 2. Parsear Botones (...)
        size_t pos = 0;
        while ((pos = buttons_part.find('(', pos)) != std::string::npos) {
            size_t end = buttons_part.find(')', pos);
            std::string content = buttons_part.substr(pos + 1, end - pos - 1);
            for (char &c : content) if (c == ',') c = ' ';
            
            std::stringstream ss_btn(content);
            std::vector<int> btn_vec(num_rows, 0);
            int idx;
            while (ss_btn >> idx) {
                if (idx < num_rows) btn_vec[idx] = 1;
            }
            m.buttons.push_back(btn_vec);
            pos = end + 1;
        }
        machines.push_back(m);
    }
    return machines;
}

// Verificación estricta: Multiplica la solución propuesta por la matriz original
// para asegurar que no hay errores de redondeo.
bool verify_solution(const Machine& m, const std::vector<long long>& x) {
    int rows = m.joltage_target.size();
    int cols = m.buttons.size();
    for (int r = 0; r < rows; ++r) {
        long long sum = 0;
        for (int c = 0; c < cols; ++c) {
            sum += x[c] * (long long)m.buttons[c][r];
        }
        if (sum != m.joltage_target[r]) return false;
    }
    return true;
}

long long solve_machine(Machine& m) {
    int rows = m.joltage_target.size(); 
    int cols = m.buttons.size();        

    // Usamos long double para minimizar errores de precisión durante Gauss
    std::vector<std::vector<long double>> matrix(rows, std::vector<long double>(cols + 1));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) matrix[r][c] = (long double)m.buttons[c][r];
        matrix[r][cols] = (long double)m.joltage_target[r];
    }

    // --- Eliminación Gaussiana ---
    int pivot_row = 0;
    std::vector<int> pivot_col_to_row(cols, -1);
    std::vector<int> free_vars;
    const long double EPS = 1e-9; 

    for (int col = 0; col < cols && pivot_row < rows; ++col) {
        // Seleccionar pivote
        int sel = -1;
        long double max_val = -1.0;

        for (int r = pivot_row; r < rows; ++r) {
            if (std::abs(matrix[r][col]) > max_val) {
                max_val = std::abs(matrix[r][col]);
                sel = r;
            }
        }

        if (max_val < EPS) {
            free_vars.push_back(col);
            continue;
        }

        // Swap y Normalización
        std::swap(matrix[pivot_row], matrix[sel]);
        pivot_col_to_row[col] = pivot_row;

        long double div = matrix[pivot_row][col];
        for (int j = col; j <= cols; ++j) matrix[pivot_row][j] /= div;

        // Hacer ceros en las otras filas
        for (int r = 0; r < rows; ++r) {
            if (r != pivot_row) {
                long double factor = matrix[r][col];
                if (std::abs(factor) > EPS) {
                    for (int j = col; j <= cols; ++j) {
                        matrix[r][j] -= factor * matrix[pivot_row][j];
                    }
                }
            }
        }
        pivot_row++;
    }

    // Identificar variables libres restantes
    for (int c = 0; c < cols; ++c) {
        bool is_recorded = false;
        for(int f : free_vars) if(f==c) is_recorded=true;
        if (!is_recorded && pivot_col_to_row[c] == -1) free_vars.push_back(c);
    }

    // --- Búsqueda Recursiva con Cotas Dinámicas ---
    long long min_presses = -1;
    std::vector<long long> current_free(free_vars.size(), 0);

    // Encontrar el valor máximo del target para seguridad
    long long max_target = 0;
    for(auto t : m.joltage_target) if(t > max_target) max_target = t;
    
    // Función recursiva
    std::function<void(int)> search = [&](int idx) {
        // Caso Base: Todas las variables libres asignadas
        if (idx == (int)free_vars.size()) {
            std::vector<long long> x(cols, 0);
            long long current_sum = 0;
            
            for(size_t i=0; i<free_vars.size(); ++i) {
                x[free_vars[i]] = current_free[i];
                current_sum += current_free[i];
            }

            // Poda: Si ya tenemos una solución mejor, no seguimos calculando
            if (min_presses != -1 && current_sum >= min_presses) return;

            bool ok = true;
            // Calcular variables pivote (Back-substitution)
            for (int c = cols - 1; c >= 0; --c) {
                if (pivot_col_to_row[c] != -1) {
                    int r = pivot_col_to_row[c];
                    long double val = matrix[r][cols];
                    for (size_t i = 0; i < free_vars.size(); ++i) {
                        val -= matrix[r][free_vars[i]] * current_free[i];
                    }
                    
                    // Verificación de Entero Positivo
                    if (val < -0.01) { ok = false; break; } 
                    long long int_val = (long long)std::round(val);
                    if (std::abs(val - int_val) > 0.01) { ok = false; break; }
                    
                    x[c] = int_val;
                    current_sum += int_val;
                }
            }

            if (ok) {
                // Verificar que la solución funciona matemáticamente
                if (verify_solution(m, x)) {
                    if (min_presses == -1 || current_sum < min_presses) {
                        min_presses = current_sum;
                    }
                }
            }
            return;
        }

        // CALCULO DE LIMITES (Crucial para no iterar infinitamente)
        // Por defecto, límite alto seguro
        long long limit = 5000; // Un valor razonable si no se encuentra cota
        int col_idx = free_vars[idx];
        
        // Revisar ecuaciones para restringir esta variable libre
        // Si la ecuación es: x_pivote + 5 * x_libre = 100
        // Entonces x_libre <= 20.
        for(int r=0; r<rows; ++r) {
            if (std::abs(matrix[r][col_idx]) > EPS && matrix[r][cols] > -EPS) {
                 if (matrix[r][col_idx] > EPS) { 
                     long long possible = (long long)(matrix[r][cols] / matrix[r][col_idx]);
                     if (possible < limit) limit = possible;
                 }
            }
        }
        
        // Iterar
        for (long long v = 0; v <= limit; ++v) {
            current_free[idx] = v;
            search(idx + 1);
        }
    };

    search(0);
    return min_presses;
}

int main() {
    // Asegúrate de usar el archivo input.txt COMPLETO
    std::vector<Machine> machines = parse_input("input.txt");
    
    long long total = 0;
    int solved = 0;
    int impossible = 0;

    std::cout << "Analizando " << machines.size() << " maquinas..." << std::endl;

    for (auto& m : machines) {
        long long res = solve_machine(m);
        if (res != -1) {
            total += res;
            solved++;
        } else {
            impossible++;
        }
    }

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Maquinas resueltas: " << solved << std::endl;
    std::cout << "Maquinas imposibles: " << impossible << std::endl;
    std::cout << "RESPUESTA FINAL (Total Presses): " << total << std::endl;

    return 0;
}
