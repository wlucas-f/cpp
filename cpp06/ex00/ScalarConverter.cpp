#include "ScalarConverter.hpp"
#include "iostream"
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <limits>
#include <string>

#define DIGITS "0123456789"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

bool isChar(std::string str){
    if(str.size() != 1)
        return (false);
    if(str.find_first_of("0123456789") != std::string::npos)
        return (false);
    return (true);
}

bool isInt(std::string str){
    size_t signalPos = 0;
    if(str[0] == '-')
        signalPos = 1;
    if(str.find_first_not_of("0123456789", signalPos) != std::string::npos)
        return(false);
    return true;
}

bool isSpecial(std::string str){
   if(str == "nan" || str == "-inf" || str == "+inf")
       return true;
   return false;
}

bool isFloat(std::string str){
    if(str[str.size() - 1] != 'f')
        return false;
    size_t dot = str.find(".");
    if(dot == std::string::npos)
        return false;
    size_t signalPos = 0;
    if(str[0] == '-')
        signalPos = 1;
    std::string decimal = str.substr(signalPos, signalPos ? dot-1 : dot);
    if(str.substr(signalPos, signalPos ? dot-1 : dot).find_first_not_of(DIGITS) != std::string::npos || decimal.empty())
        return false;
    std::string fractional = str.substr(dot + 1, str.size() - dot - 2);
    if(fractional.empty() || fractional.find_first_not_of(DIGITS) != std::string::npos)
        return false;
    return true;
}

bool isDouble(std::string str){
    if(str[str.size() - 1] == 'f')
        return false;
    size_t dot = str.find(".");
    if(dot == std::string::npos)
        return false;
    size_t signalPos = 0;
    if(str[0] == '-')
        signalPos = 1;
    std::string decimal = str.substr(signalPos, signalPos ? dot-1 : dot);
    if(decimal.find_first_not_of(DIGITS) != std::string::npos || decimal.empty())
        return false;
    std::string fractional = str.substr(dot + 1, str.size() - dot - (signalPos ? 1 : 0));
    if(fractional.empty() || fractional.find_first_not_of(DIGITS) != std::string::npos)
        return false;
    return true;
}

types whichType(std::string str){
    if(isChar(str)) return CHAR;
    if(isInt(str)) return INT;
    if(isSpecial(str)) return SPECIAL;
    if(isFloat(str)) return FLOAT;
    if(isDouble(str)) return DOUBLE;
    return INVALID;
}

void convertToChar(const char &c){
	if(std::numeric_limits<char>::max() <= c)
		std::cout << "char: overflow\n";
	else
		std::cout << "char: " << c << "\n";
}

void convertFromChar(const std::string str){
	convertToChar(str[0]);
	std::cout << "int: " << static_cast<int>(str[0]) << "\n";
	std::cout << "float: " << static_cast<float>(str[0]) << "\n";
	std::cout << "double: " << static_cast<double>(str[0]) << "\n";
}

void convertFromNumber(const std::string str){
	long double number = strtold(str.c_str(), NULL);
	convertToChar(number);
	if(number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		std::cout << "int: overflow\n";
	else
		std::cout << "int: " << static_cast<int>(number) << "\n";
	if(std::numeric_limits<float>::min() >= number || std::numeric_limits<float>::max() <= number)
		std::cout << "float: overflow\n";
	else
		std::cout << "float: " << strtof(str.c_str(), NULL) << "\n";
	if(std::numeric_limits<double>::min() >= number || std::numeric_limits<double>::max() <= number)
		std::cout << "int: overflow\n";
	else
		std::cout << "int: " << static_cast<double>(number) << "\n";
}

void ScalarConverter::convert(const std::string &str){
    types type = whichType(str);
    switch (type) {
        case CHAR: convertFromChar(str); break; //convertFromChar
        case INT: case FLOAT: case DOUBLE:
        	convertFromNumber(str); break;
        case SPECIAL: std::cout << "its special\n"; break;
        case INVALID: std::cout << "its INVALID\n"; break;
    }
}
    //    	std::cout << "itsnumber\n"; break;
