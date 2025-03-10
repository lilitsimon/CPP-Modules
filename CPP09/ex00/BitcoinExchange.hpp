#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, float> exchangeRates; // map is a container that stores key-value pairs in an ordered manner. Here date and price. It automatically sorts by date and allows fast lookup of the closest lower date
    
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value) const;
    float getExchangeRate(const std::string& date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processInputFile(const std::string& inputFile);
};

#endif
