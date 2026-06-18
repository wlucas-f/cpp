#include "ScalarConverter.hpp"
#include "iostream"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

types whichType(std::string str){
	size_t dot = str.find(".");
	size_t f = str.find("f");

	if(dot == std::string::npos && f == std::string::npos)
	{
		// isChar
		// isInt
		// isSpecial
	}
	if(dot != std::string::npos && f != std::string::npos)
		//isFloat
	if(dot != std::string::npos && f == std::string::npos)
			//isDouble
}

void ScalarConverter::convert(const std::string &str){
	types type = whichType(str);
	switch (type) {
		case CHAR: std::cout << "its char"; break;
		case INT: std::cout << "its int"; break;
		case FLOAT: std::cout << "its float"; break;
		case DOUBLE: std::cout << "its double"; break;
		case SPECIAL: std::cout << "its special"; break;
		case INVALID: std::cout << "its INVALID"; break;
	}
}
