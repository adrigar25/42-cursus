#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string line;
    long long ranges[1000][2];
    long long temp[2];
    int j = 0;

    int numRanges = 0;
    long long totalNums = 0;
    
    
    while (std::getline(infile, line) && !line.empty())
    {
        ranges[numRanges][0] = std::stoll(line.substr(0, line.find('-')));
        ranges[numRanges][1] = std::stoll(line.substr(line.find('-') + 1));
        numRanges++;
    }
    
    
    for(int i = 0; i < numRanges - 1; i++)
    {
        for(int j = 0; j < numRanges - i - 1; j++)
        {
            if(ranges[j][0] > ranges[j + 1][0])
            {
                
                temp[0] = ranges[j][0];
                temp[1] = ranges[j][1];
                ranges[j][0] = ranges[j + 1][0];
                ranges[j][1] = ranges[j + 1][1];
                ranges[j + 1][0] = temp[0];
                ranges[j + 1][1] = temp[1];
            }
        }
    }

     for(int i = 0; i < numRanges; i++)
    {
        std::cout << ranges[i][0] << "-" << ranges[i][1] << std::endl;
    }

    std::cout << "----" << std::endl;
    
    
    // Mergear rangos que se solapan o son contiguos
    for(int i = 0; i < numRanges - 1; i++)
    {
       if(ranges[i + 1][0] <= ranges[i][1] + 1)
       {
            // Extender el rango actual hasta el máximo
            ranges[i][1] = std::max(ranges[i][1], ranges[i + 1][1]);
            
            // Desplazar todos los rangos siguientes
            for(int j = i + 1; j < numRanges - 1; j++)
            {
                ranges[j][0] = ranges[j + 1][0];
                ranges[j][1] = ranges[j + 1][1];
            }
            
            numRanges--;
            i--;  // Volver a comprobar desde el mismo índice
       }
    }


    for(int i = 0; i < numRanges; i++)
    {
        std::cout << ranges[i][0] << "-" << ranges[i][1] << std::endl;
    }

    for(int i = 0; i < numRanges; i++)
    {
        if(ranges[i][0] == 0 && ranges[i][1] == 0)
            continue;
        totalNums += (ranges[i][1] - ranges[i][0] + 1);
    }


    std::cout << totalNums << std::endl;
    
    return 0;
}
