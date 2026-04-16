#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream csv("./data.csv");
    std::string line;
    std::string date;
    size_t comma;
    double exchange_rate;

    if(!csv.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return ;
    }

    std::getline(csv, line);
    while (std::getline(csv, line))
    {
        comma = line.find(',');
        date = line.substr(0, comma);
        exchange_rate = std::atof(line.substr(comma + 1).c_str());
        _prices[date] = exchange_rate;
    }

};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _prices(other._prices){};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
        _prices = other._prices;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){};

static bool is_valid_date(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2)
    {
        bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (is_leap_year ? 29 : 28))
            return false;
    }

    return true;
}

void BitcoinExchange::getPriceByDate(std::string date, double value)
{
    if(!is_valid_date(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }

    if(value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }

    if(value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }

    std::map<std::string, double>::iterator it = _prices.lower_bound(date);
    if (it == _prices.end() || it->first != date)
    {
        if (it == _prices.begin())
        {
            std::cout << "Error: no data available for this date." << std::endl;
            return ;
        }
        --it;
    }

    std::cout << date << " => " << value << " = " << value * it->second << std::endl;  
}

