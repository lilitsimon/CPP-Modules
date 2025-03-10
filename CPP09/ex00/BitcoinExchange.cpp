#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) { // this reads and stores Bitcoin exchange rate database
    std::ifstream file(dbFile); // input file stream
    if(!file) {
        std::cerr << "Error: could no open the database file" << std::endl;
        exit(1);
    }
    std::string line;
    bool isHeader = true; // to ignore hthe header

    while(std::getline(file, line)) {
        if(isHeader) {
            isHeader = false; // marks that we processed the header
            continue;
        }
    
    std::stringstream ss(line); //creating an ss stream from the line. So that we can use >> or std::getline() to extract parts of line
    std::string date;
    float rate;

    if(std::getline(ss, date, ',') && (ss >> rate)) // This line extracts the date and rate from ss (a std::stringstream containing a line from the file) and stores them in a std::map. then Reads the remaining part of the string and converts it into a float.
        exchangeRates[date] = rate; // after this we get: exchangeRates["2011-01-03"] = 0.3 for example
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->exchangeRates = other.exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if(date.length() != 10 || date[4] != '-' || date [7] != '-')
        return false;
        int year;
        int month;
        int day;
        char dash1;
        char dash2;

        std::stringstream ss(date); // Converts the date string into a stringstream (ss).
        if(!(ss >> year >> dash1 >> month >> dash2 >> day)) // reading and assigning one by one the values
            return false;
        return (dash1 == '-' && dash2 == '-' && month >=1 && month <=12 && day >=1 && day <=31);
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    float num;
    std::stringstream ss(value);
    if (!(ss >> num) || ss.fail())
        return false;
    return (num >= 0 && num <= 1000);
}


float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.end() || it->first != date) {
        if (it == exchangeRates.begin()) {
            std::cerr << "Error: No exchange rate available for date " << date << std::endl;
            return -1;
        }
        --it; // Move to the previous valid date
    }

    return it->second;
}



void BitcoinExchange::processInputFile(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if(!file) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    std::string line;
    bool isHeader = true;

    while(std::getline(file, line)) {
        if(isHeader) {
            isHeader = false;
            continue;
        }

        std::stringstream ss(line);
        std::string date;
        std::string value;

        if(std::getline(ss, date, '|') && std::getline(ss, value)) {
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);


            if(!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!isValidValue(value)) {
                if (std::atof(value.c_str()) > 1000)
                    std::cerr << "Error: too large a number." << std::endl;
                else
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            float btcValue = std::atof(value.c_str());
            float rate = getExchangeRate(date);

            if(rate != -1)
                std::cout << date << " => " << btcValue << " = " << (btcValue * rate) << std::endl;
        }
        else
            std::cerr << "Error: bad format => " << line << std::endl;
    }
}