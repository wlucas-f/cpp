#include "whatever.hpp"

int main(){
	int n1 = 1;
	int n5 = 9;
	std::cout << "min(1, 9): ";
	std::cout << ::min(n1, n5) << "\n";
	std::cout << "max(1, 9): ";
	std::cout << ::max(n1, n5) << "\n";

	std::cout << "Before swap:\n";
	std::cout << "n1: " << n1;
	std::cout << "\nn5: " << n5;

	::swap(n1, n5);
	std::cout << "\nAfter swap:\n";
	std::cout << "n1: " << n1;
	std::cout << "\nn5: " << n5 << std::endl;
}
