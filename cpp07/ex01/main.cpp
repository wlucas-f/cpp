#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &elem){
	std::cout << elem << std::endl;
}

template <typename T>
void increment(T &elem){
	elem++;
}

int main(void){
	std::cout << "=== Test 1: print int array ===\n";
	int intArr[] = {1, 2, 3, 4, 5};
	::iter(intArr, 5, print<int>);

	std::cout << "\n=== Test 2: increment int array ===\n";
	::iter(intArr, 5, increment<int>);
	::iter(intArr, 5, print<int>);

	std::cout << "\n=== Test 3: print double array ===\n";
	double dblArr[] = {1.1, 2.2, 3.3};
	::iter(dblArr, 3, print<double>);

	std::cout << "\n=== Test 4: print string array ===\n";
	std::string strArr[] = {"hello", "world", "42"};
	::iter(strArr, 3, print<std::string>);

	std::cout << "\n=== Test 5: const int array ===\n";
	const int constArr[] = {10, 20, 30};
	::iter(constArr, 3, print<int>);

	std::cout << "\n=== Test 6: empty array (no output expected) ===\n";
	int emptyArr[] = {0};
	::iter(emptyArr, 0, print<int>);
	std::cout << "(nothing printed)\n";

	std::cout << "\n=== Test 7: single element array ===\n";
	char charArr[] = {'A'};
	::iter(charArr, 1, print<char>);
}
