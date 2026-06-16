#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm{
    private:
        std::string const _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
    public:
        AForm();
        AForm(std::string name, bool isSigned, const int gradeToSign, const int gradeToExec);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        ~AForm();
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
        class NotSignedFormException : public std::exception{
			public:
				const char *what() const throw();
		};
        void beSigned(Bureaucrat &bureucrat);
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
