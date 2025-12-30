#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <fstream>

// Structure to represent a Junction Box position
struct Point {
    int id;
    long long x, y, z;
};

// Structure to represent a potential connection (Edge)
struct Edge {
    int u; // Index of first box
    int v; // Index of second box
    long long distSq; // Squared Euclidean distance (avoids costly sqrt)

    // Overload < operator for sorting
    bool operator<(const Edge& other) const {
        return distSq < other.distSq;
    }
};

// Disjoint Set Union (DSU) structure to manage circuits
struct DSU {
    std::vector<int> parent;
    std::vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1); // Initially, every box is a circuit of size 1
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the set
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    // Unite two sets
    // Returns true if a merge happened, false if they were already connected
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Merge smaller tree into larger tree
            if (size[root_i] < size[root_j])
                std::swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
        // If root_i == root_j, "nothing happens" logic is handled here 
        // (we just don't change anything), but the calling function 
        // still counts the edge as processed.
    }
};

long long distSq(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + 
           (a.y - b.y) * (a.y - b.y) + 
           (a.z - b.z) * (a.z - b.z);
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open input.txt" << std::endl;
        return 1;
    }

    std::vector<Point> boxes;
    std::string line;
    int id_counter = 0;

    // 1. Parse Input
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        Point p;
        p.id = id_counter++;
        char comma; // To eat the commas
        std::stringstream ss(line);
        if (ss >> p.x >> comma >> p.y >> comma >> p.z) {
            boxes.push_back(p);
        }
    }

    // 2. Generate all possible edges
    std::vector<Edge> edges;
    int n = boxes.size();
    // Pre-allocate memory to avoid reallocations
    edges.reserve(n * (n - 1) / 2); 

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({i, j, distSq(boxes[i], boxes[j])});
        }
    }

    // 3. Sort edges by distance (ascending)
    std::sort(edges.begin(), edges.end());

    // 4. Process the first 1000 shortest connections
    DSU circuits(n);
    int limit = std::min((int)edges.size(), 1000);

    for (int i = 0; i < limit; ++i) {
        circuits.unite(edges[i].u, edges[i].v);
    }

    // 5. Collect circuit sizes
    std::vector<long long> sizes;
    for (int i = 0; i < n; ++i) {
        // Only count the size if 'i' is the root of a set
        // (This prevents double counting nodes in the same set)
        if (circuits.parent[i] == i) {
            sizes.push_back(circuits.size[i]);
        }
    }

    // 6. Sort sizes descending to find the largest
    std::sort(sizes.rbegin(), sizes.rend());

    // 7. Calculate result
    long long result = 0;
    if (sizes.size() >= 3) {
        result = sizes[0] * sizes[1] * sizes[2];
        std::cout << "Top 3 sizes: " << sizes[0] << ", " << sizes[1] << ", " << sizes[2] << std::endl;
    } else {
        std::cout << "Fewer than 3 circuits found. Multiplying what exists." << std::endl;
        result = 1;
        for (long long s : sizes) result *= s;
    }

    std::cout << "Answer: " << result << std::endl;

    return 0;
}