#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <string>

static std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return std::string();
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    std::ifstream input(argv[1]);
    std::string line;

    if (!input.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::getline(input, line);
    while (std::getline(input, line))
    {
        size_t sep = line.find('|');
        if (sep == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, sep));
        std::string value_str = trim(line.substr(sep + 1));
        if (date.empty() || value_str.empty())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::stringstream ss(value_str.c_str());
        double value;
        if (!(ss >> value) || value < 0)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        btc.getPriceByDate(date, value);
    }
    return 0;
}
