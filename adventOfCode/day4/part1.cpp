#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string line;
    std::vector<std::string> grid;

    while (std::getline(infile, line))
    {
        grid.push_back(line);
    }
    infile.close();

    int rows = grid.size();
    int totalRemoved = 0;
    bool changed = true;
    int adjacent = 0;
    int cols = 0;
    
    while (changed)
    {
        changed = false;
        
        for(int i = 0; i < rows; i++)
        {
            cols = grid[i].length();
            for(int j = 0; j < cols; j++) 
            {
                if(grid[i][j] == '@')
                {
                    adjacent = 0;
                    if (j + 1 < cols && grid[i][j + 1] == '@')
                        adjacent++;
                    if (j - 1 >= 0 && grid[i][j - 1] == '@')
                        adjacent++;
                    if (i + 1 < rows && grid[i + 1][j] == '@')
                        adjacent++;
                    if (i - 1 >= 0 && grid[i - 1][j] == '@')
                        adjacent++;
                    if (i + 1 < rows && j + 1 < cols && grid[i + 1][j + 1] == '@')
                        adjacent++;
                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == '@')
                        adjacent++;
                    if (i + 1 < rows && j - 1 >= 0 && grid[i + 1][j - 1] == '@')
                        adjacent++;
                    if (i - 1 >= 0 && j + 1 < cols && grid[i - 1][j + 1] == '@')
                        adjacent++;
                    if(adjacent < 4)
                    {
                        grid[i][j] = 'x';
                        totalRemoved++;
                        changed = true;
                    }
                }
            }
        }
    }
    std::cout << totalRemoved << std::endl;
    return 0;
}
