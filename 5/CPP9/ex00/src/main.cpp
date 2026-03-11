#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>



int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }

    BitcoinExchange btc;
    std::ifstream input(argv[1]);
    std::string line;

    if(!input.is_open())
    {
        std::cout << "Error: could not open input file" << std::endl;
        return (1);
    }

    std::getline(input, line);
    while (std::getline(input, line))
    {
        size_t sep = line.find(" | ");
        if(sep == std::string::npos)
            btc.getPriceByDate(line, 0.0);
        else
            btc.getPriceByDate(line.substr(0, sep), std::atof(line.substr(sep + 3).c_str()));
    }
    return (0);
}
