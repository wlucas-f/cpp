#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <exception>

class Intern{
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();
		AForm *makeShrubberyCreationForm(std::string formTarget) const;
		AForm *makeRobotomyRequestForm(std::string formTarget) const;
		AForm *makePresidentialPardonForm(std::string formTarget) const;
		AForm *makeForm(std::string formName, std::string formTarget) const;
		class NoOptionsAvailableException : public std::exception{
			public:
				const char * what() const throw();
		};
};

#endif
