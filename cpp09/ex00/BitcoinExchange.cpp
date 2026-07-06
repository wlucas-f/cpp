#include "BitcoinExchange.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}



void BitcoinExchange::displayResult(std::string date, double value){

	std::map<std::string, double>::iterator it = pairs.lower_bound(date);

	if(it != pairs.end()){
		if(it->first != date && it != pairs.begin())
			it--;
		std::cout << date << " => " << value << " = " << it->second * value << "\n";
	}
	else
		std::cout << "Not found\n";
}

void BitcoinExchange::setPair(std::pair<std::string, double> value){
	pairs.insert(value);
}

void BitcoinExchange::printMap(){
	std::map<std::string, double>::iterator it = pairs.begin();
	for(; it != pairs.end(); it++)
		std::cout << "\n" << it->first << " " << it->second << "\n";
}
