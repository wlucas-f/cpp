#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

//class Bureaucrat;

class Form{
    private:
        std::string const _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
    public:
        Form();
        Form(std::string name, bool isSigned, const int gradeToSign, const int gradeToExec);
        Form(const Form &other);
        Form& operator=(const Form &other);
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        ~Form();
        class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();
		};
        class GradeTooLowException : public std::exception{
       		private:
         		std::string _message;
            public:
           		GradeTooLowException();
           		GradeTooLowException(std::string message);
                const char *what() const throw();
                ~GradeTooLowException() throw();
        };
        void beSigned(Bureaucrat &bureucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
