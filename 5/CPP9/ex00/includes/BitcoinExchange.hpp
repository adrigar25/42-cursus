#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>


class BitcoinExchange
{
private:
    std::map<std::string, double> _prices;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange& operator=(const BitcoinExchange &other);
    void getPriceByDate(std::string date, double value);
    ~BitcoinExchange(); 
};

#endif