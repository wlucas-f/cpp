#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::parseLine(std::string &line, char delim){
	std::stringstream ss(line);

	std::string date;
	getline(ss, date, delim);
	parseDate();

	std::string value;
	getline(ss, value);
	parseValue();

	pairs[date] = value;
}

void BitcoinExchange::printMap(){
	std::map<std::string, std::string>::iterator it = pairs.begin();
	for(; it != pairs.end(); it++)
		std::cout << "\n" << it->first << " " << it->second << "\n";
}
