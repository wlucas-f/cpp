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

void ScalarConverter::convert(char *string){
    std::cout << "char: " << static_cast<char>(*string) << "\n";
    std::cout << "int: " << static_cast<int>(*string) << "\n";
    std::cout << "float: " << static_cast<float>(*string) << "\n";
    std::cout << "double: " << static_cast<double>(*string) << "\n";
}
