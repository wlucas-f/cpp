#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

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
		~Form();
		void beSigned();
		void signForm();
};

#endif
