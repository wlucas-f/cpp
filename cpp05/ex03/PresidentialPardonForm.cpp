#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <string>

int PresidentialPardonForm::sign = 25;
int PresidentialPardonForm::exec = 5;

PresidentialPardonForm::PresidentialPardonForm():AForm("presidential pardon", false, PresidentialPardonForm::sign, PresidentialPardonForm::exec), _target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("presidential pardon", false, PresidentialPardonForm::sign, PresidentialPardonForm::exec), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other), _target(other._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if(this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    std::cout << "Your suspicious activities with unconventional medical interventions were investigated.\nThe President is the only person who can save you...\n" << std::endl;
	if(!this->getIsSigned())
		throw AForm::NotSignedFormException();
	if(executor.getGrade() > PresidentialPardonForm::exec)
		throw AForm::GradeTooLowException("Wait till you grow bigger in the corporate ladder, you maggot!");
	std::cout << "By decree of President Zaphod Beeblebrox, " << _target << " is pardoned — their name erased from the records; go in peace under the protection of the Republic's Seal.\n" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}
