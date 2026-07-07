#include "RPN.hpp"


RPN::RPN(){}

RPN::RPN(const RPN &other):stack(other.stack){}

RPN& RPN::operator=(const RPN &other){
    if(this != &other)
        this->stack = other.stack;
    return *this;
}

RPN::~RPN(){}
