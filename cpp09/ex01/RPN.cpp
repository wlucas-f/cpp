#include "RPN.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>


RPN::RPN(){}

RPN::RPN(const RPN &other):stack(other.stack){}

RPN& RPN::operator=(const RPN &other){
	if(this != &other)
		this->stack = other.stack;
	return *this;
}

void RPN::doOp(std::string token)
{
	if (stack.size() <= 1)
		throw std::runtime_error("Error");

	int v1 = stack.top();
	stack.pop();
	if(token == "/" && v1 == 0)
		throw std::runtime_error("Invalid division");

	int v2 = stack.top();
	stack.pop();

	switch(token[0])
	{
		case '*': stack.push(v2 * v1); break;
		case '/': stack.push(v2 / v1); break;
		case '+': stack.push(v2 + v1); break;
		case '-': stack.push(v2 - v1); break;
	}
}

void RPN::displayResult()
{
	if(stack.size() != 1)
		throw std::runtime_error("Error");
	while(!stack.empty())
	{
		std::cout << stack.top() << "\n";
		stack.pop();
	}
}


void RPN::solve(const std::string &str){
	std::stringstream input(str);
	std::string token;

	const std::string validDigits("0123456789 ");
	const std::string validOperands("+-/*");

	if (str.find_first_not_of(validDigits + validOperands) != std::string::npos)
		throw std::runtime_error("Error");

	while(input >> token)
	{
		if(token.size() != 1)
			throw std::runtime_error("Error");
		if(validOperands.find(token) != std::string::npos)
			doOp(token);
		else
			stack.push(std::atoi(token.c_str()));
	}
	displayResult();
}


RPN::~RPN(){}
