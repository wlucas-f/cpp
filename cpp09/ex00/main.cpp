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
        throw std::runtime_error("Error: too large a number.");
    return ret;
}

void parseDate(std::string &date){
	date.erase(10);

	double year = std::strtod(date.substr(0, 4).c_str(), NULL);
	double month = std::strtod(date.substr(5, 6).c_str(), NULL);
	double day = std::strtod(date.substr(8, 9).c_str(), NULL);
	bool ans = true;

	if(year < 2008 || year > 2022)
		ans = false;
	else if(month < 1 || month > 12)
		ans = false;
	else if(day < 1 || day > 31)
		ans = false;
	else if(month == 02)
	{
		bool leap = (static_cast<int>(year) % 400 == 0)
				|| (static_cast<int>(year) % 4 == 0 && static_cast<int>(year) % 100 != 0);
		if ((leap && day > 29) || (!leap && day > 28))
			ans = false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			ans = false;
	}

	if(ans == false)
	{
		std::string errmsg("Error: bad input => " + date);
		throw std::runtime_error(errmsg);
	}
}

void parseLine(BitcoinExchange &db, std::string &line, char delim){
    std::stringstream ss(line);

    try{
	    std::string date;
	    getline(ss, date, delim);
	    parseDate(date);
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
}
