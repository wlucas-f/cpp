#pragma once

#include <map>
class BitcoinExange{
    private:
        std::map<typename Key, typename Tp>;
    public:
        BitcoinExange();
        BitcoinExange(const BitcoinExange& other);
        BitcoinExange& operator=(const BitcoinExange& other);
        ~BitcoinExange();
};
