#pragma once

#include <exception>
#include <vector>
class Span{
	private:
		unsigned int n;
		std::vector<int> storage;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void addNumber(int num);
		void addMultipleNumbers(std::vector<int>::iterator b, std::vector<int>::iterator e);
		int shortestSpan();
		int longestSpan();
		class FullStorageException: public std::exception{
			public:
				const char * what() const throw();
		};
		class NoSpanCanBeFoundException: public std::exception{
			public:
				const char * what() const throw();
		};
};
