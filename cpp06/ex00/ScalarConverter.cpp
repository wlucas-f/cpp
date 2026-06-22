#include "ScalarConverter.hpp"
#include "iostream"
#include <cctype>
#include "iomanip"
#include "iostream"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <limits>
#include <string>
#include <math.h>

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
    if(str.find_first_of(DIGITS) != std::string::npos)
        return (false);
    return (true);
}

bool isInt(std::string str){
    size_t signalPos = 0;
    if(str[0] == '-')
        signalPos = 1;
    if(str.find_first_not_of(DIGITS, signalPos) != std::string::npos)
        return(false);
    return true;
}

bool isSpecial(std::string str){
   if(str == "nan" || str == "-inf" || str == "+inf"
       || str == "nanf" || str == "-inff" || str == "+inff" ||
       str == "inf" || str == "inff")
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

void displayResults(long double value, std::string str)
{
    if(value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: " << "impossible\n";
    else
    {
        if(!std::isprint(static_cast<char>(value)))
            std::cout << "char: " << "Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(value) << "'\n";
    }
    if(value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()
        || str == "nan" || str == "nanf")
        std::cout << "int: " << "impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";
    std::streamsize	original_precision = std::cout.precision();
    std::cout << std::fixed << std::setprecision(1);
    if((value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
    	&& value == value && !isinf(value))
        std::cout << "float: " << "impossible\n";
    else
        std::cout << "float: " << static_cast<float>(value) << "f\n";
    if((value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
    	&& value == value && !isinf(value))
        std::cout << "double: " << "impossible\n";
    else
        std::cout << "double: " << static_cast<double>(value) << "\n";
    std::cout.unsetf(std::ios::fixed);
	std::cout.precision(original_precision);
}

void ScalarConverter::convert(const std::string &str){
    types type = whichType(str);
    if(type == INVALID)
    {
        std::cout << "Invalid Input\n";
        return ;
    }
    long double value = std::strtold(str.c_str(), NULL);
    if(type == CHAR)
    	value = str.at(0);
    displayResults(value, str);
}
