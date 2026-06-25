#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void increment(T &elem)
{
	elem++;
}

template <typename T>
void printDouble(const T &elem)
{
	std::cout << elem * 2 << std::endl;
}

int main(void)
{
	std::cout << "=== Test 1: print int array ===" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	::iter(intArr, 5, print<int>);

	std::cout << "\n=== Test 2: increment int array ===" << std::endl;
	::iter(intArr, 5, increment<int>);
	::iter(intArr, 5, print<int>);

	std::cout << "\n=== Test 3: print double array ===" << std::endl;
	double dblArr[] = {1.1, 2.2, 3.3};
	::iter(dblArr, 3, print<double>);

	std::cout << "\n=== Test 4: printDouble on double array ===" << std::endl;
	::iter(dblArr, 3, printDouble<double>);

	std::cout << "\n=== Test 5: print string array ===" << std::endl;
	std::string strArr[] = {"hello", "world", "42"};
	::iter(strArr, 3, print<std::string>);

	std::cout << "\n=== Test 6: const int array ===" << std::endl;
	const int constArr[] = {10, 20, 30};
	::iter(constArr, 3, print<int>);

	std::cout << "\n=== Test 7: empty array (no output expected) ===" << std::endl;
	int emptyArr[] = {0};
	::iter(emptyArr, 0, print<int>);
	std::cout << "(nothing printed)" << std::endl;

	std::cout << "\n=== Test 8: single element array ===" << std::endl;
	char charArr[] = {'A'};
	::iter(charArr, 1, print<char>);
}
