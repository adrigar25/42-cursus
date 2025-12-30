#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

// Grafo global
std::map<std::string, std::vector<std::string>> adj;

// Cache para memoization
std::map<std::string, long long> memo;

// Función recursiva para contar caminos desde 'start' hasta 'target'
long long count_paths(const std::string& current, const std::string& target) {
    // Si llegamos al destino, encontramos 1 camino válido
    if (current == target) {
        return 1;
    }
    
    // Si ya calculamos este nodo para este objetivo, devolver valor
    if (memo.count(current)) {
        return memo[current];
    }

    long long total = 0;
    if (adj.count(current)) {
        for (const std::string& neighbor : adj[current]) {
            total += count_paths(neighbor, target);
        }
    }

    return memo[current] = total;
}

// Función auxiliar (wrapper) para limpiar la cache y calcular segmento
long long get_segment_count(const std::string& from, const std::string& to) {
    memo.clear(); // IMPORTANTE: La cache depende del destino, hay que limpiarla
    return count_paths(from, to);
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open input.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t colon_pos = line.find(':');
        std::string source = line.substr(0, colon_pos);
        std::string destinations_str = line.substr(colon_pos + 1);

        std::stringstream ss(destinations_str);
        std::string dest;
        while (ss >> dest) {
            adj[source].push_back(dest);
        }
    }
    file.close();

    // --- ESCENARIO 1: svr -> dac -> fft -> out ---
    long long svr_to_dac = get_segment_count("svr", "dac");
    long long dac_to_fft = get_segment_count("dac", "fft");
    long long fft_to_out = get_segment_count("fft", "out");
    
    long long paths_dac_first = svr_to_dac * dac_to_fft * fft_to_out;

    // --- ESCENARIO 2: svr -> fft -> dac -> out ---
    long long svr_to_fft = get_segment_count("svr", "fft");
    long long fft_to_dac = get_segment_count("fft", "dac");
    long long dac_to_out = get_segment_count("dac", "out");

    long long paths_fft_first = svr_to_fft * fft_to_dac * dac_to_out;

    // Sumamos ambos escenarios
    long long total_result = paths_dac_first + paths_fft_first;

    std::cout << "Scenario 1 (dac then fft): " << paths_dac_first << std::endl;
    std::cout << "Scenario 2 (fft then dac): " << paths_fft_first << std::endl;
    std::cout << "Total paths visiting both: " << total_result << std::endl;

    return 0;
}