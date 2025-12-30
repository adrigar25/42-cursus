#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include <cmath>

// Estructura para representar una máquina
struct Machine {
    std::vector<int> target_state; // Estado objetivo (Vector b)
    std::vector<std::vector<int>> buttons; // Matriz de botones (transpuesta de A)
};

// Función para limpiar caracteres no numéricos para el parsing
std::string clean_line(std::string s) {
    for (char &c : s) {
        if (c == ',' || c == '(' || c == ')') {
            c = ' ';
        }
    }
    return s;
}

// Parsea el input.txt
std::vector<Machine> parse_input(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Machine> machines;
    
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        Machine m;

        // 1. Parsear el estado objetivo [...]
        size_t open_bracket = line.find('[');
        size_t close_bracket = line.find(']');
        std::string state_str = line.substr(open_bracket + 1, close_bracket - open_bracket - 1);
        
        for (char c : state_str) {
            m.target_state.push_back((c == '#') ? 1 : 0);
        }

        // 2. Parsear los botones (...)
        // Cortamos el string después del estado para buscar los paréntesis
        std::string wiring_part = line.substr(close_bracket + 1);
        size_t brace_pos = wiring_part.find('{'); // Ignoramos lo que haya en {}
        if (brace_pos != std::string::npos) {
            wiring_part = wiring_part.substr(0, brace_pos);
        }

        // Buscamos grupos (...)
        size_t pos = 0;
        while ((pos = wiring_part.find('(', pos)) != std::string::npos) {
            size_t end = wiring_part.find(')', pos);
            std::string content = wiring_part.substr(pos + 1, end - pos - 1);
            
            // Reemplazamos comas por espacios para usar stringstream
            std::replace(content.begin(), content.end(), ',', ' ');
            
            std::stringstream ss(content);
            std::vector<int> button_effect(m.target_state.size(), 0);
            int light_idx;
            while (ss >> light_idx) {
                if (light_idx < (int)button_effect.size()) {
                    button_effect[light_idx] = 1;
                }
            }
            m.buttons.push_back(button_effect); // Cada botón es una columna conceptual
            pos = end + 1;
        }
        machines.push_back(m);
    }
    return machines;
}

// Resuelve una máquina individual usando Eliminación Gaussiana GF(2)
long long solve_machine(Machine& m) {
    int rows = m.target_state.size(); // Cantidad de luces (ecuaciones)
    int cols = m.buttons.size();      // Cantidad de botones (variables)

    // Construir Matriz Aumentada [Botones | Target]
    // matrix[row][col]
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols + 1));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            matrix[r][c] = m.buttons[c][r]; // Nota: m.buttons[c] es el vector efecto del botón c
        }
        matrix[r][cols] = m.target_state[r]; // Última columna es el objetivo
    }

    // Eliminación Gaussiana (Gauss-Jordan)
    int pivot_row = 0;
    std::vector<int> pivot_col_to_row(cols, -1); // Mapa: qué fila controla este pivote
    std::vector<int> free_vars; // Índices de columnas que son variables libres

    for (int col = 0; col < cols && pivot_row < rows; ++col) {
        // Buscar fila con 1 en esta columna (desde pivot_row hacia abajo)
        int sel = -1;
        for (int r = pivot_row; r < rows; ++r) {
            if (matrix[r][col] == 1) {
                sel = r;
                break;
            }
        }

        if (sel == -1) {
            // No hay pivote en esta columna -> es variable libre
            free_vars.push_back(col);
            continue;
        }

        // Intercambiar fila seleccionada con la fila pivote actual
        std::swap(matrix[pivot_row], matrix[sel]);
        pivot_col_to_row[col] = pivot_row;

        // Hacer ceros en las otras filas (XOR)
        for (int r = 0; r < rows; ++r) {
            if (r != pivot_row && matrix[r][col] == 1) {
                for (int k = col; k <= cols; ++k) {
                    matrix[r][k] ^= matrix[pivot_row][k];
                }
            }
        }
        pivot_row++;
    }

    // Recoger variables libres restantes (si hubo columnas al final sin procesar)
    for (int col = 0; col < cols; ++col) {
        bool is_pivot = (pivot_col_to_row[col] != -1);
        bool is_recorded_free = false;
        for(int f : free_vars) if(f == col) is_recorded_free = true;
        
        if (!is_pivot && !is_recorded_free) {
            free_vars.push_back(col);
        }
    }

    // Verificar filas imposibles (0 0 ... 0 | 1)
    // Las filas desde pivot_row hasta el final deben ser todo ceros en la parte aumentada
    for (int r = pivot_row; r < rows; ++r) {
        if (matrix[r][cols] == 1) {
            return -1; // Sistema inconsistente (sin solución)
        }
    }

    // Minimización: Probar todas las combinaciones de variables libres
    // Como pulsamos botones, buscamos minimizar la suma de x_i
    long long min_presses = LLONG_MAX;
    int num_free = free_vars.size();
    
    // Si hay muchas variables libres, esto podría ser lento (2^N), 
    // pero en este tipo de problemas N suele ser pequeño.
    unsigned long long combinations = 1ULL << num_free; 

    for (unsigned long long i = 0; i < combinations; ++i) {
        std::vector<int> x(cols, 0);
        long long current_presses = 0;

        // 1. Asignar valores a variables libres según los bits de i
        for (int b = 0; b < num_free; ++b) {
            if ((i >> b) & 1) {
                x[free_vars[b]] = 1;
                current_presses++;
            }
        }

        // 2. Calcular variables pivote (Back-substitution simplificada por Gauss-Jordan)
        // Como hicimos Jordan (ceros arriba y abajo), x_pivot = Target ^ Suma(vars_libres_en_fila)
        // Iteramos desde la última columna hacia la primera para mantener orden lógico,
        // aunque con Jordan puro es directo.
        for (int col = cols - 1; col >= 0; --col) {
            if (pivot_col_to_row[col] != -1) {
                int r = pivot_col_to_row[col];
                int val = matrix[r][cols]; // Valor del target modificado
                
                // XOR con los valores ya determinados a la derecha
                for (int k = col + 1; k < cols; ++k) {
                    if (matrix[r][k] == 1) {
                        val ^= x[k];
                    }
                }
                x[col] = val;
                if (val == 1) current_presses++;
            }
        }

        if (current_presses < min_presses) {
            min_presses = current_presses;
        }
    }

    return (min_presses == LLONG_MAX) ? 0 : min_presses;
}

int main() {
    std::vector<Machine> machines = parse_input("input.txt");
    long long total_presses = 0;

    std::cout << "Procesando " << machines.size() << " maquinas..." << std::endl;

    for (size_t i = 0; i < machines.size(); ++i) {
        long long res = solve_machine(machines[i]);
        if (res == -1) {
            std::cout << "Maquina " << (i+1) << ": Imposible de resolver." << std::endl;
        } else {
            total_presses += res;
            // Debug opcional:
            // std::cout << "Maquina " << (i+1) << ": " << res << " pulsaciones." << std::endl;
        }
    }

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Total fewest button presses: " << total_presses << std::endl;

    return 0;
}
