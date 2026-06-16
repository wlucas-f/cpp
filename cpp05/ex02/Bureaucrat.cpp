#include "Bureaucrat.hpp"
#include "AForm.hpp"

int Bureaucrat::highestGrade = 1;
int Bureaucrat::lowestGrade = 150;

Bureaucrat::Bureaucrat():_name("Default"), _grade(Bureaucrat::lowestGrade){}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade){
	if(grade < highestGrade)
		throw Bureaucrat::GradeTooHighException();
	if(grade > lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if(this != &other)
		_grade = other._grade;
	return *this;
}

const std::string Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "A Bureaucrat can't be that good by definition!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Only Kafka can describe such a terrible Bureaucrat!";
}

void Bureaucrat::incrementGrade(){
	if(this->_grade == highestGrade)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(){
	if(this->_grade == lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

Bureaucrat::~Bureaucrat(){}

void Bureaucrat::signForm(AForm &AForm){
    try{
        AForm.beSigned(*this);
        std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
    }catch(std::exception &e){
        std::cout << this->getName() << " couldn't sign " << AForm.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}
