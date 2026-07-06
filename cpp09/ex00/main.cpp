#include "BitcoinExchange.hpp"
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

char parseHeader(std::string &line){
    char delim = EOF;

    if(line == "date,exchange_rate")
        delim = ',';
    if(line == "date | value")
        delim = '|';
    return delim;
}

double parseValue(std::string &afterDelim){
    double ret = std::strtod(afterDelim.c_str(), NULL);
    if (ret < 0)
        throw std::runtime_error("Error: not a positive number.");
    if (ret > std::numeric_limits<int>::max())
        throw std::runtime_error("Error: too a large number.");
    return ret;
}

void parseLine(BitcoinExchange &db, std::string &line, char delim){
    std::stringstream ss(line);

    std::string date;
    getline(ss, date, delim);
    if (date.length() > 11)
         date.erase(11);

//    std::cout << "X" << date.at(date.length()) << "X\n";

    std::cout << "->" << date << "<-\n";
    //parseDate();

    try{
        std::string afterDelim;
        getline(ss, afterDelim);
        double value = parseValue(afterDelim);

        if(delim == ',')
            db.setPair(make_pair(date, value));
        else
            db.displayResult(date, value);
    }catch (std::exception &e){ std::cerr << e.what() << "\n";}

}

int parseFile(BitcoinExchange &db, std::ifstream &dbName){
    std::string line;

    if(dbName.is_open())
    {
        getline(dbName, line);
        char c = parseHeader(line);
        if (c == EOF)
            return 1;

        while (getline(dbName, line)){
            parseLine(db, line, c);
        }
    }
    return 0;
}

int main(int argc, char **argv){
    if(argc != 2 || !argv[1][0])
        return 1;

    std::ifstream dbName("data.csv");
    BitcoinExchange db;
    parseFile(db, dbName);

    std::ifstream inputFile(argv[1]);
    parseFile(db, inputFile);
    //inputDb.printMap();

}
