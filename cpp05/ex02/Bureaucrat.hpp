#ifndef BUREAUCRAT_CPP
#define BUREAUCRAT_CPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		~Bureaucrat();
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw();
		};
		static int highestGrade;
		static int lowestGrade;
		void signForm(AForm &AForm);
		void executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
