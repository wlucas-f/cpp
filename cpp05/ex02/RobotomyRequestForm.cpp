#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <string>

int RobotomyRequestForm::sign = 72;
int RobotomyRequestForm::exec = 45;

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy Request Form", false, RobotomyRequestForm::sign, RobotomyRequestForm::exec), _target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("Robotomy Request Form", false, RobotomyRequestForm::sign, RobotomyRequestForm::exec), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm("Robotomy Request Form", false, RobotomyRequestForm::sign, RobotomyRequestForm::exec), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if(this != &other)
		_target = other._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if(!this->getIsSigned())
		throw AForm::NotSignedFormException();
	if(executor.getGrade() > RobotomyRequestForm::exec)
		throw AForm::GradeTooLowException("Wait till you grow bigger in the corporate ladder, you maggot!");
	std::cout << "Suddenly you hear drilling noises coming from the corridor:\n *Whirr!! Whirr!! Whirr!!*\n" << std::endl;
	std::cout << "The creepy doctor entered the room, you can't remember who was behind that mask. But he said:" << std::endl;
	srand((unsigned) time(NULL));
	int random = rand() % 50;
	if(random <=24)
	    std::cout << "- Congratulations! " << _target << " was robotomized successfully.\n" << std::endl;
	else
        std::cout << "- I'm sorry for your loss, " << _target << "'s robotomy failed\n" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){}
