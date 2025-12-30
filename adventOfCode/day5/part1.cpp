#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string line;
    long long ranges[1000][2];
    int fresh = 0;
    long long id;
    int j = 0;

    for (int i = 0; std::getline(infile, line) && line != ""; i++)
    {
        ranges[i][0] = std::stoll(line.substr(0, line.find('-')));
        ranges[i][1] = std::stoll(line.substr(line.find('-') + 1));
        
    }
    
    
    while (std::getline(infile, line))
    {
        if(line == "")
            continue;
        for(int i = 0; ranges[i][0] || ranges[i][1]; i++)
        {
            id = std::stoll(line);
            if(id >= ranges[i][0] && id <= ranges[i][1])
            {
                fresh++;
                break;
            }
        }
    }

    std::cout << fresh << std::endl;
    
    return 0;
}
