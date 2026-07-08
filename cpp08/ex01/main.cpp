#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	std::cout << "---Subject test---\n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---10001 test---\n";
	{
		Span sp = Span(10001);
		std::vector<int> vec;
		srand((unsigned int)time(NULL));
		for(int i = 0; i < 10001; i++){
			int random = rand() % 100 + (i * 10);
			vec.push_back(random);
		}
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::vector<int> storage = sp.getStorage();
		// std::vector<int>::iterator it = storage.begin();
		// for(; it != storage.end(); it++){
		// 	std::cout << *it << "\n";
		// }

		std::cout << "\n\nShortest span: " << sp.shortestSpan();
		std::cout << "\nLongest span: " << sp.longestSpan();
	}
	std::cout << "\n\n";
}
