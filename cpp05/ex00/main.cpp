#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(){

	std::cout << "---Out of range constructor 1---\n\n";
	{
		try{
			Bureaucrat tH("Travis", 0);
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "---Out of range constructor 2---\n\n";
	{
		try{
			Bureaucrat tL("Miguel", 151);
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "---Insertion operator Overload---\n\n";
	{
		Bureaucrat J("Janio", 75);
		std::cout << J;
	}
	std::cout << std::endl << std::endl;

	std::cout << "---Increment and decrement grade---\n\n";
	{
		Bureaucrat mid("Steve", 75);
		std::cout << mid;
		std::cout << "After increment: \n";
		try{
			mid.incrementGrade();
			std::cout << mid;
			std::cout << "After decrement: \n";
			mid.decrementGrade();
			std::cout << mid;
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		Bureaucrat notSoBad("Notch", 1);
		std::cout << notSoBad;

		try{
			std::cout << "After increment: \n";
			notSoBad.incrementGrade();
			std::cout << notSoBad;
			std::cout << "After decrement: \n";
			notSoBad.decrementGrade();
			std::cout << notSoBad;
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		Bureaucrat reallyBad("Aima", 150);
		std::cout << reallyBad;

		try{
			std::cout << "After decrement: \n";
			reallyBad.decrementGrade();
			std::cout << reallyBad;
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

	}
	std::cout << std::endl << std::endl;
}
