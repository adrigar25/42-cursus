#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>      // Para sqrt y pow
#include <algorithm>  // Para sort
#include <functional> // Para greater (ordenar descendente)


int main(void)
{
    std::ifstream infile("input.txt");
    if (!infile.is_open()) {
        std::cout << "Error: No se pudo abrir input.txt" << std::endl;
        return 1;
    }

    std::string line;
    int redtiles[1000][2];  // Aumentar tamaño para seguridad
    int count = 0;

    // Leer líneas del archivo
   while (std::getline(infile, line) && count < 1000) 
   {
        size_t comma_pos = line.find(',');
        
        redtiles[count][0] = std::stoi(line.substr(0, comma_pos));
        redtiles[count][1] = std::stoi(line.substr(comma_pos + 1));
        
        count++;
    }
    
    std::cout << "Total lines read: " << count << std::endl;

    std::vector<long long> areas;
    areas.reserve(count * count); // Pre-reservar espacio

    int k = 0;
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            if(i == j) continue; 
            std::cout << "Creating rectangle " << k << " with corners (" << redtiles[i][0] << "," << redtiles[i][1] << ") and (" << redtiles[j][0] << "," << redtiles[j][1] << ")" << std::endl;
            
            long long width = std::abs(redtiles[i][0] - redtiles[j][0]) + 1;
            long long height = std::abs(redtiles[i][1] - redtiles[j][1]) + 1;
            long long area = width * height;
            
            std::cout << "Width: " << width << ", Height: " << height << std::endl;
            std::cout << "Area: " << area << std::endl;
            areas.push_back(area);
            k++;
        }
    }
    
    std::cout << "Total rectangles created: " << k << std::endl;


    long long max_area = 0;
    for(int i = 0; i < k; i++) {
        if(areas[i] > max_area) {
            max_area = areas[i];
        }
    }
    std::cout << "Max area: " << max_area << std::endl; 
    
    return 0;
}
