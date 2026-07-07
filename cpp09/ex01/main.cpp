#include "RPN.hpp"
#include <iostream>
#include <string>
#include <bits/stdc++.h>

int main(int argc, char **argv)
{
    if(argc != 2 || !argv[1][0])
    {
        std::cerr << "Error: Invalid arguments\n";
        return 1;
    }
    std::string input = argv[1];
    const std::string validTokens("0123456789 +-/*");

    if (int pos = input.find_first_not_of(validTokens) != std::string::npos)
    {
        std::cerr << "Error: Invalid arguments\n";
        return 1;
    }

    // char c = 0;
    // for(int i = 0; i < input.length(); i++)
    // {
    //     c = input.at(i);

    // }
}
