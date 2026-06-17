#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(){}

Intern::Intern(const Intern &other){
	(void)other;
}

Intern& Intern::operator=(const Intern &other){
	(void)other;
	return (*this);
}

Intern::~Intern(){}

AForm *Intern::makeShrubberyCreationForm(std::string formTarget) const{
	return (new ShrubberyCreationForm(formTarget));
}
AForm *Intern::makeRobotomyRequestForm(std::string formTarget) const{
	return (new RobotomyRequestForm(formTarget));
}
AForm *Intern::makePresidentialPardonForm(std::string formTarget) const{
	return (new PresidentialPardonForm(formTarget));
}

const char * Intern::NoOptionsAvailableException::what() const throw(){
	return "Invalid form name";
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) const{
	typedef AForm* (Intern::*fptr)(std::string formTarget) const;
	std::string options[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	fptr ptr[3] = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	for(int i = 0; i < 3; i++)
	{
		if(formName == options[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*ptr[i])(formTarget);
		}
	}
	throw NoOptionsAvailableException();
}
