#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(){
	std::cout << "---Intern Request Test 1---\n\n";
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat staff("Bocal", 41);
		try{
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			staff.signForm(*rrf);
			staff.executeForm(*rrf);
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "---Intern Request Test 2---\n\n";
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat staff("Bocal", 41);
		try{
			rrf = someRandomIntern.makeForm("robotomy request form", "Bender");
			staff.signForm(*rrf);
			staff.executeForm(*rrf);
		}catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}
