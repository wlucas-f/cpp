#include "Form.hpp"

Form::Form():_name("Default"), _isSigned(false), _gradeToSign(75), _gradeToExec(75){}

Form::Form(std::string name, bool isSigned, const int gradeToSign, const int gradeToExec):_name(name), _isSigned(false), _gradeToSign(75), _gradeToExec(75){}

Form::Form(const Form &other):_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){}

Form& Form::operator=(const Form &other){
	if(this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form(){}

void beSigned();

void signForm();
