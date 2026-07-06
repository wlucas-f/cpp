#pragma once

#include <map>
#include <string>
#include <utility>

class BitcoinExchange{
    private:
        std::map<std::string, double> pairs;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        void printMap();
        void displayResult(std::string date, double value);
        void setPair(std::pair<std::string, double>);
};
