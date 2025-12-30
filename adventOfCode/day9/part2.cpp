#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>      // Para sqrt y pow
#include <algorithm>  // Para sort
#include <functional> // Para greater (ordenar descendente)

void fillLine(int y, int x_start, int x_end, long long map[][100000]) {
    for (int x = x_start; x <= x_end; x++) {
        map[x][y] = 1;
    }
}

void fillColumn(int x, int y_start, int y_end, long long map[][100000]) {
    for (int y = y_start; y <= y_end; y++) {
        map[x][y] = 1;
    }
}


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

    return 0;
}
