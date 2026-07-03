#include "BitcoinExchange.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>

char parseHeader(std::string &line){
	char delim = EOF;

	if(line == "date,exchange_rate")
		delim = ',';
	if(line == "date | value")
		delim = '|';
	return delim;
}

int main(int argc, char **argv){
	if(argc != 2 || !argv[1][0])
		return 1;
	std::string line;
	std::ifstream dbName(argv[1]);
	BitcoinExchange db;
	if(dbName.is_open())
	{
		getline(dbName, line);
		char c = parseHeader(line);
		if (c == EOF)
			return 1;
		while (getline(dbName, line)){
			std::cout << line << "\n";
			db.parseLine(line, c);
		}
		db.printMap();
	}
}
