#include <fstream>
#include <iostream>
#include <string>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string line;


    int dial = 50;
    int count = 0;
    int num;

    while (std::getline(infile, line))
    {
        std::cout << "Processing line: " << line << std::endl;
        num = std::stoi(line.substr(1));
        std::cout << "Number extracted: " << num << std::endl;

        for(int i = 0; i < num; i++) 
        {
            dial += (line[0] == 'L') ? -1 : 1;

            if (dial < 0)
                dial = 99;
            else if (dial >= 100)
                dial = 0;

            if (dial == 0)
                count++;
        }

        std::cout << "Dial position before wrap: " << dial << std::endl;

        std::cout << "Dial position after wrap: " << dial << std::endl;
    }

    std::cout << "Final dial position: " << dial << std::endl;
    std::cout << "Number of times dial landed on 0: " << count << std::endl;
    
}