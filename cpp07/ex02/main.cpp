#include  "Array.hpp"
#include <exception>
#include <iostream>

int main(){
	std::cout << "------Default Constructor------\n";
	{
		Array<int> arrayInt;
		std::cout << arrayInt.size() << "\n";
	}
	std::cout << "------N elements, Operator and size test------\n";
	{
		int szarr = 3;
		Array<int> sarrayInt(szarr);
		std::cout << "Array size: " << sarrayInt.size() << std::endl;
		for (int i = 0; i < szarr; i++)
			sarrayInt[i] = i;
		for (int i = 0; i < szarr; i++)
			std::cout << sarrayInt[i] << "\n";
	}
	std::cout << "\n\n";
	std::cout << "------Copy Constructor------\n";
	{
		Array<std::string> original(3);
		std::cout << "Original before change: \n";
		original[0] = "original";
		original[1] = "original";
		original[2] = "original";
		for (int i = 0; i < 3; i++)
			std::cout << original[i] << "\n";

		Array<std::string> copy(original);
		std::cout << "Copy before change: \n";
		for (int i = 0; i < 3; i++)
			std::cout << copy[i] << "\n";

		std::cout << "Copy after change: \n";
		copy[0] = "copy";
		copy[1] = "copy";
		copy[2] = "copy";
		for (int i = 0; i < 3; i++)
			std::cout << copy[i] << "\n";
		std::cout << "Original after copy change: \n";
		for (int i = 0; i < 3; i++)
			std::cout << original[i] << "\n";
	}
	std::cout << "\n\n";
	std::cout << "------Out Of Bounds test------\n";
	{
		Array<int>*	ptr = NULL;
	 	try{
			ptr = new Array<int>(10);
			std::cout << "Array size: " << ptr->size() << std::endl;
			std::cout << (*ptr)[15];
		}catch(const std::exception &e){
			std::cerr << "Exception: " << e.what() << "\n";
		}
		delete ptr;
	}
	std::cout << "\n\n";
}
