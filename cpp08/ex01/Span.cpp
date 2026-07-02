#include "Span.hpp"
#include <climits>
#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>

Span::Span():n(0){};

Span::Span(unsigned int n):n(n){}

Span::Span(const Span &other){
	this->n = other.n;
}

Span& Span::operator=(const Span &other){
	if(this != &other)
		this->n = other.n;
	return *this;
}

Span::~Span(){}

void Span::addNumber(int num){
	if(storage.size() >= n)
		throw FullStorageException();
	storage.push_back(num);
}

void Span::addMultipleNumbers(std::vector<int>::iterator b, std::vector<int>::iterator e){
	for(;b != e; b++){
		if(storage.size() >= n)
			throw FullStorageException();
		storage.push_back(*b);
	}
}

std::vector<int> Span::getStorage() const{
	return this->storage;
}

int Span::shortestSpan(){
	if(storage.size() < 2)
		throw NoSpanCanBeFoundException();
	std::vector<int>::iterator it = storage.begin();
	std::sort(it, storage.end());
	int min = std::numeric_limits<int>::max();
	int diff = 0;
	for(; it != storage.end() - 1; it++){
		diff = std::abs(*(it + 1) - std::abs(*it));
		if(diff < min)
			min = diff;
	}
	return min;
}


int Span::longestSpan(){
	if(storage.size() < 2)
		throw NoSpanCanBeFoundException();
	return(*std::max_element(storage.begin(), storage.end()) -
			*std::min_element(storage.begin(), storage.end()));
}

const char * Span::FullStorageException::what() const throw(){
	return "Can't exceed the maximum storage.";
}

const char * Span::NoSpanCanBeFoundException::what() const throw(){
	return "No span can be found.";
}
