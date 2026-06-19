#include "ScalarConverter.hpp"
#include "iostream"
#include <cctype>
#include <cstddef>
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
    if(str[0] == '+' || str[0] == '-')
        signalPos = 1;
    if(str.find_first_not_of("0123456789", signalPos) != std::string::npos)
        return(false);
    return true;
}

bool isSpecial(std::string str){
   if(str == "nan" || str == "inf" || str == "-inf" || str == "+inf")
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
    if(str[0] == '+' || str[0] == '-')
        signalPos = 1;
    if(str.substr(signalPos, dot -1).find_first_not_of(DIGITS) != std::string::npos)
        return false;
    if(str.substr(dot + 1, str.size() - dot - signalPos ? 1 : 0 - 1).find_first_not_of(DIGITS) != std::string::npos)
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
    if(str[0] == '+' || str[0] == '-')
        signalPos = 1;
    if(str.substr(signalPos, dot -1).find_first_not_of(DIGITS) != std::string::npos)
        return false;
    if(str.substr(dot + 1, str.size() - dot - signalPos ? 1 : 0).find_first_not_of(DIGITS) != std::string::npos)
        return false;
    return true;
}

types whichType(std::string str){
    size_t dot = str.find(".");
    size_t f = str.find("f");

    if(isChar(str)) return CHAR;
    if(isInt(str)) return INT;
    if(isSpecial(str)) return SPECIAL;
    if(isFloat(str)) return FLOAT;
    if(dot != std::string::npos && f == std::string::npos && isDouble(str))
        return DOUBLE;
    else
        return INVALID;
}

void ScalarConverter::convert(const std::string &str){
    types type = whichType(str);
    switch (type) {
        case CHAR: std::cout << "its char\n"; break;
        case INT: std::cout << "its int\n"; break;
        case FLOAT: std::cout << "its float\n"; break;
        case DOUBLE: std::cout << "its double\n"; break;
        case SPECIAL: std::cout << "its special\n"; break;
        case INVALID: std::cout << "its INVALID\n"; break;
    }
}
