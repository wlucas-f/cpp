#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

int main(int argc, char **argv)
{
    if(argc != 2 || !argv[1][0])
    {
        std::cerr << "Error\n";
        return 1;
    }

    std::string  input(argv[1]);
    RPN expression;
    try{
    	expression.solve(input);
    }catch(std::exception &e){
    	std::cerr << e.what() << "\n";
    }
}
