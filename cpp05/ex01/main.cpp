#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main(){

	std::cout << "---Out of range constructor 1---\n\n";
	{
		try{
			Form indepedenceLetter("Independence Letter", false, 0, 0);
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "---Out of range constructor 2---\n\n";
	{
		try{
		    Form tissue("Tissue", false, 151, 151);
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "---Insertion operator Overload---\n\n";
	{
		Form f("FAAAAA!", false, 75, 75);
		std::cout << f;
	}
	std::cout << std::endl << std::endl;
