#pragma once

#include <map>
#include <string>

class BitcoinExchange{
    private:
        std::map<std::string, std::string> pairs;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        void parseLine(std::string &line, char delim);
        void printMap();
};
