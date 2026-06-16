#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():_name("Default"), _isSigned(false), _gradeToSign(75), _gradeToExec(75){}

Form::Form(std::string name, bool isSigned, const int gradeToSign, const int gradeToExec):_name(name), _isSigned(false), _gradeToSign(75), _gradeToExec(75){
    (void)isSigned;
    if(gradeToSign < Bureaucrat::highestGrade || gradeToExec < Bureaucrat::highestGrade)
        throw Form::GradeTooHighException();
    if(gradeToSign > Bureaucrat::lowestGrade || gradeToExec > Bureaucrat::lowestGrade)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other):_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){}

Form& Form::operator=(const Form &other){
	if(this != &other)
		_isSigned = other._isSigned;
	return *this;
}

const std::string Form::getName() const{
	return this->_name;
}

bool Form::getIsSigned() const{
	return this->_isSigned;
}

int Form::getGradeToSign() const{
	return this->_gradeToSign;
}

int Form::getGradeToExec() const{
	return this->_gradeToExec;
}

Form::~Form(){}

const char *Form::GradeTooHighException::what() const throw(){
	return "Not even the president has enought grade for that, who would have tought?";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "No one will sign your tissue, c'mon!";
}

const char *Form::TooLowToSignException::what() const throw(){
	return "of the low rank, mind your own business!";
}

void Form::beSigned(Bureaucrat &bureaucrat){
    if(bureaucrat.getGrade() > _gradeToSign)
        throw TooLowToSignException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f){
   out << "Form: " << f.getName() << "\nIs signed? " << (f.getIsSigned() ? "True" : "False") << "\nGrade to sign: " << f.getGradeToSign()
   << "\nGrade to execute: " << f.getGradeToExec();
   return out;
}
