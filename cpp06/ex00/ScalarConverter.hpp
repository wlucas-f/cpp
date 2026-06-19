#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum types{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID
};

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &str);
};

types whichType(std::string str);
bool isChar(std::string str);
bool isInt(std::string str);
bool isSpecial(std::string str);
bool isFloat(std::string str);
bool isDouble(std::string str);

#endif
