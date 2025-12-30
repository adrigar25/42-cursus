#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

std::map<std::string, std::vector<std::string>> adj;

std::map<std::string, long long> memo;

long long count_paths(const std::string& current_node) {
    if (current_node == "out") {
        return 1;
    }
    if (memo.count(current_node)) {
        return memo[current_node];
    }

    long long total_paths = 0;
    if (adj.count(current_node)) {
        for (const std::string& neighbor : adj[current_node]) {
            total_paths += count_paths(neighbor);
        }
    }

    return memo[current_node] = total_paths;
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

        // Parsing the line: "name: dest1 dest2 dest3"
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

    // Start the search from "you"
    long long result = count_paths("you");

    std::cout << "Total distinct paths from 'you' to 'out': " << result << std::endl;

    return 0;
}