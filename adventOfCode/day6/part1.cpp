#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string lines[5];
    static long nums[10000][5] = {0};
    long total = 0;
    long current;
    
    for(int i = 0; i < 5; ++i) {
        std::getline(infile, lines[i]);
    }


    for(int i = 0; i < 5; ++i) {
        int col = 0;  // Contador de columnas
        size_t j = 0;
        
        while(j < lines[i].size()) {
            // Saltar espacios
            while(j < lines[i].size() && lines[i][j] == ' ')
                j++;
            
            if(j >= lines[i].size()) break;
            
            // Si es operador
            if(lines[i][4] == '+') {
                nums[col][4] = 0;
                col++;
                j++;
                continue;
            }
            if(lines[i][4] == '*') {
                nums[col][4] = -1;
                col++;
                j++;
                continue;
            }
            long num = 0;
            while(j < lines[i].size() && lines[i][j] >= '0' && lines[i][j] <= '9') {
                num = num * 10 + (lines[i][j] - '0');
                j++;
            }
            nums[col][i] = num;
            col++;
        }
    }

    for(int col = 0; col < 1000; col++)
    {
        current = 0;
        for(int row = 0; row < 4; row++)
        {
           if(nums[col][4] == -1)
           {
                if(current == 0)
                current = 1;
               current *= nums[col][row];
           }
           else
           {
               current += nums[col][row];
        }
        total += current;
    }

    std::cout << "Total: " << total << std::endl;

    return 0;
}
