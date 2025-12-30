#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

// Representa una coordenada (fila, columna)
struct Point {
    int r, c;
    bool operator<(const Point& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
    }
};

// Una forma es un conjunto de puntos ocupados
struct Shape {
    int id;
    int width, height;
    vector<Point> cells; // Puntos relativos al bounding box (0,0)
    int area;
};

// Almacena todas las variaciones únicas (rotaciones/flips) de una forma base
struct ShapeVariations {
    vector<Shape> variations;
};

vector<ShapeVariations> all_shapes;

// Normaliza una forma: mueve sus puntos para que el bounding box empiece en (0,0)
Shape normalize(vector<Point>& points, int id) {
    if (points.empty()) return {id, 0, 0, {}, 0};
    int min_r = 1e9, min_c = 1e9;
    int max_r = -1e9, max_c = -1e9;
    
    for (auto& p : points) {
        min_r = min(min_r, p.r);
        min_c = min(min_c, p.c);
        max_r = max(max_r, p.r);
        max_c = max(max_c, p.c);
    }
    
    Shape s;
    s.id = id;
    s.height = max_r - min_r + 1;
    s.width = max_c - min_c + 1;
    s.area = points.size();
    
    for (auto& p : points) {
        s.cells.push_back({p.r - min_r, p.c - min_c});
    }
    // Ordenar puntos para facilitar comparaciones y cache
    sort(s.cells.begin(), s.cells.end());
    return s;
}

// Genera todas las 8 variaciones de una forma
void generate_variations(int id, const vector<string>& raw_shape) {
    vector<Point> base_points;
    for (int r = 0; r < raw_shape.size(); ++r) {
        for (int c = 0; c < raw_shape[r].size(); ++c) {
            if (raw_shape[r][c] == '#') {
                base_points.push_back({r, c});
            }
        }
    }

    set<vector<Point>> unique_hashes;
    ShapeVariations sv;

    // Intentar 4 rotaciones
    vector<Point> current = base_points;
    for (int i = 0; i < 4; ++i) {
        // Guardar actual normalizada
        Shape s = normalize(current, id);
        if (unique_hashes.find(s.cells) == unique_hashes.end()) {
            unique_hashes.insert(s.cells);
            sv.variations.push_back(s);
        }
        
        // Rotar 90 grados: (r, c) -> (c, -r)
        vector<Point> next_rot;
        for (auto& p : current) {
            next_rot.push_back({p.c, -p.r});
        }
        current = next_rot;
    }

    // Flip (Reflexión) y repetir rotaciones
    current.clear();
    for (auto& p : base_points) {
        current.push_back({p.r, -p.c}); // Flip horizontal
    }
    
    for (int i = 0; i < 4; ++i) {
        Shape s = normalize(current, id);
        if (unique_hashes.find(s.cells) == unique_hashes.end()) {
            unique_hashes.insert(s.cells);
            sv.variations.push_back(s);
        }
        vector<Point> next_rot;
        for (auto& p : current) {
            next_rot.push_back({p.c, -p.r});
        }
        current = next_rot;
    }
    
    all_shapes.push_back(sv);
}

// --- BACKTRACKING ---

int H, W;
vector<vector<bool>> grid;
vector<int> pieces_to_place; // IDs de las formas a colocar

// Verifica si una variación específica cabe en (r, c)
bool can_fit(const Shape& s, int r, int c) {
    if (r + s.height > H || c + s.width > W) return false;
    for (const auto& p : s.cells) {
        if (grid[r + p.r][c + p.c]) return false;
    }
    return true;
}

// Coloca o quita una forma del tablero
void toggle_shape(const Shape& s, int r, int c, bool val) {
    for (const auto& p : s.cells) {
        grid[r + p.r][c + p.c] = val;
    }
}

// Función recursiva principal
bool solve(int idx, int start_pos_1d) {
    // Caso base: hemos colocado todas las piezas
    if (idx == pieces_to_place.size()) return true;

    int shape_id = pieces_to_place[idx];
    const auto& vars = all_shapes[shape_id].variations;

    // Optimización de simetría para piezas idénticas:
    // Si la pieza actual es igual a la anterior, no empezar desde 0,
    // sino desde donde colocamos la anterior.
    int start_r = 0, start_c = 0;
    if (idx > 0 && pieces_to_place[idx] == pieces_to_place[idx-1]) {
        // Convertir índice 1D a 2D
        start_r = start_pos_1d / W;
        start_c = start_pos_1d % W;
    } else {
        start_pos_1d = 0; 
    }

    // Iterar por el tablero
    // Truco: aplanamos el bucle para facilitar el manejo del "start_pos"
    for (int i = start_pos_1d; i < H * W; ++i) {
        int r = i / W;
        int c = i % W;

        // Intentar todas las variaciones de la pieza
        for (const auto& s : vars) {
            // Poda simple: si la pieza se sale del ancho restante en esta fila, a veces se puede saltar,
            // pero con formas irregulares es mejor checkear can_fit.
            
            if (can_fit(s, r, c)) {
                toggle_shape(s, r, c, true); // Colocar
                
                // Recurse
                // Pasamos 'i' como el start_pos para la siguiente pieza si es idéntica
                if (solve(idx + 1, i)) return true;
                
                toggle_shape(s, r, c, false); // Backtrack
            }
        }
    }

    return false;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error: input.txt no encontrado" << endl;
        return 1;
    }

    string line;
    vector<string> current_shape_lines;
    int current_id = -1;
    bool parsing_shapes = true;
    
    // Almacenamos líneas de regiones para procesar después
    vector<string> region_lines;

    // Fase 1: Parseo
    while (getline(file, line)) {
        if (line.empty()) {
            if (!current_shape_lines.empty()) {
                generate_variations(current_id, current_shape_lines);
                current_shape_lines.clear();
            }
            continue;
        }

        // Detectar si es una línea de región (contiene 'x' y ':')
        if (line.find('x') != string::npos && line.find(':') != string::npos && line.find('#') == string::npos) {
            parsing_shapes = false;
            region_lines.push_back(line);
            continue;
        }

        if (parsing_shapes) {
            // Es parte de una definición de forma
            if (line.find(':') != string::npos) {
                // Nueva forma, ej "0:"
                if (!current_shape_lines.empty()) {
                    generate_variations(current_id, current_shape_lines);
                    current_shape_lines.clear();
                }
                current_id++; // Asumimos orden secuencial 0, 1, 2...
            } else {
                current_shape_lines.push_back(line);
            }
        }
    }
    // Procesar última forma si quedó pendiente
    if (!current_shape_lines.empty()) {
        generate_variations(current_id, current_shape_lines);
    }

    // Fase 2: Resolver Regiones
    int success_count = 0;
    cout << "Procesando " << region_lines.size() << " regiones..." << endl;

    for (const string& rline : region_lines) {
        // Parsear "12x5: 1 0 1..."
        stringstream ss(rline);
        string dims_part, counts_part;
        getline(ss, dims_part, ':');
        getline(ss, counts_part);

        size_t x_pos = dims_part.find('x');
        W = stoi(dims_part.substr(0, x_pos));
        H = stoi(dims_part.substr(x_pos + 1));

        stringstream ss_counts(counts_part);
        int count;
        int shape_idx = 0;
        pieces_to_place.clear();
        
        long long total_area_needed = 0;
        while (ss_counts >> count) {
            for (int i = 0; i < count; ++i) {
                pieces_to_place.push_back(shape_idx);
                if (shape_idx < all_shapes.size())
                    total_area_needed += all_shapes[shape_idx].variations[0].area;
            }
            shape_idx++;
        }

        // Poda por área
        if (total_area_needed > (long long)W * H) {
            continue; 
        }

        // Ordenar piezas para optimizar backtracking
        // 1. Las más grandes primero (fallan antes si no caben)
        // 2. Agrupar piezas idénticas para la poda de simetría
        sort(pieces_to_place.begin(), pieces_to_place.end(), [](int a, int b) {
            int area_a = all_shapes[a].variations[0].area;
            int area_b = all_shapes[b].variations[0].area;
            if (area_a != area_b) return area_a > area_b; // Descendente por área
            return a < b; // Agrupar por ID
        });

        // Preparar grid
        grid.assign(H, vector<bool>(W, false));

        if (solve(0, 0)) {
            success_count++;
            // cout << "Region " << rline << " -> FIT" << endl;
        } else {
            // cout << "Region " << rline << " -> FAIL" << endl;
        }
    }

    cout << "Answer: " << success_count << endl;

    return 0;
}