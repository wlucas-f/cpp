#include  "Array.hpp"
#include  "Array.tpp"
#include <exception>
#include <iostream>

int main(){
	// std::cout << "------Default Constructor------\n";
	// {
	// 	Array<int> arrayInt;
	// 	std::cout << arrayInt.;
	// }
	std::cout << "------Size test------\n";
	{
		Array<int> arrayInt(8);
		std::cout << "Array size: " << arrayInt.size() << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "------Operator test------\n";
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
	std::cout << "------Out Of Bounds test------\n";
	{
		Array<int> tarrayInt(10);
		std::cout << "Array size: " << tarrayInt.size() << std::endl;
	 try{
			std::cout << tarrayInt[15];
		}catch(std::exception &e){
			std::cerr << "Exception: " << e.what() << "\n";
		}
	}
	std::cout << "\n\n";
}
