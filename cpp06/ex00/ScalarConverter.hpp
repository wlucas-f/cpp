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

#endif
