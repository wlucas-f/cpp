#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc != 2 || !argv[1][0])
        return 1;
    ScalarConverter::convert(argv[1]);
}
