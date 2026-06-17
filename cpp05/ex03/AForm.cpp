#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm():_name("Default"), _isSigned(false), _gradeToSign(75), _gradeToExec(75){}

AForm::AForm(std::string name, bool isSigned, const int gradeToSign, const int gradeToExec):_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
    (void)isSigned;
    if(gradeToSign < Bureaucrat::highestGrade || gradeToExec < Bureaucrat::highestGrade)
        throw AForm::GradeTooHighException();
    if(gradeToSign > Bureaucrat::lowestGrade || gradeToExec > Bureaucrat::lowestGrade)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other):_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){}

AForm& AForm::operator=(const AForm &other){
	if(this != &other)
		_isSigned = other._isSigned;
	return *this;
}

const std::string AForm::getName() const{
	return this->_name;
}

bool AForm::getIsSigned() const{
	return this->_isSigned;
}

int AForm::getGradeToSign() const{
	return this->_gradeToSign;
}

int AForm::getGradeToExec() const{
	return this->_gradeToExec;
}

AForm::~AForm(){}

const char *AForm::GradeTooHighException::what() const throw(){
	return "Not even the president has enought grade for that, who would have tought?";
}

const char *AForm::NotSignedFormException::what() const throw(){
	return "Im sorry, can't help you with that... \nThe form isn't signed and we can't do that for you in this department, come back when you have everything in hands.";
}

AForm::GradeTooLowException::GradeTooLowException():_message("No one will sign your tissue, c'mon!"){}

AForm::GradeTooLowException::GradeTooLowException(std::string message):_message(message){}

const char *AForm::GradeTooLowException::what() const throw(){
	return _message.c_str();
}

void AForm::beSigned(Bureaucrat &bureaucrat){
    if(bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException("of the low rank, mind your own business!");
    _isSigned = true;
}

AForm::GradeTooLowException::~GradeTooLowException() throw(){}

std::ostream &operator<<(std::ostream &out, const AForm &f){
   out << f.getName() << "\nIs signed? " << (f.getIsSigned() ? "True" : "False") << "\nGrade to sign: " << f.getGradeToSign()
   << "\nGrade to execute: " << f.getGradeToExec();
   return out;
}
