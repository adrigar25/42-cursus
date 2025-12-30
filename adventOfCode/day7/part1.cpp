#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string lines[142];
    int start = 0;
    int splitted = 0;
    
    for(int i = 0; i < 141; i++)
    {
        std::getline(infile, lines[i]);
    }

    for (start = 0; lines[0][start] && lines[0][start] != 'S'; start++);

    std::cout << "Start at: " << start << std::endl;

    lines[1][start] = '|';

    for(int i = 2; lines[i][0];i++)
    {
        for(int j = 0; lines[i][j];j++)
        {
            if(lines[i][j] == '^' && lines[i - 1][j] == '|')
            {
                if(lines[i][j - 1] && lines[i][j - 1] == '.')
                    lines[i][j - 1] = '|';
                if(lines[i][j + 1] && lines[i][j + 1] == '.')
                    lines[i][j + 1] = '|';

                splitted++;
            } 
            else if(lines[i][j] == '.' && lines[i - 1][j] == '|')
            {
                lines[i][j] = '|';
            }
            
        }
    }
    
    for(int i = 0; lines[i][0];i++)
        std::cout << lines[i] << std::endl;

    std::cout << "Splitted: " << splitted << std::endl;

    
    return 0;
}
