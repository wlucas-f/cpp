#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

int ShrubberyCreationForm::sign = 145;
int ShrubberyCreationForm::exec = 137;

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery Creation Form", false, ShrubberyCreationForm::sign, ShrubberyCreationForm::exec), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("Shrubbery Creation Form", false, ShrubberyCreationForm::sign, ShrubberyCreationForm::exec), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm("Shrubbery Creation Form", false, ShrubberyCreationForm::sign, ShrubberyCreationForm::exec), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if(this != &other)
		_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if(!this->getIsSigned())
		throw AForm::NotSignedFormException();
	if(executor.getGrade() > ShrubberyCreationForm::exec)
		throw AForm::GradeTooLowException("Wait till you grow bigger in the corporate ladder, you maggot!");
	std::ofstream outFile((_target+"_shrubbery").c_str());

	outFile		<< "     &&& &&& &&&\n"
			    << "   &&& &&& &&& &&&\n"
			    << " &&& &&& &&& &&& &&&\n"
			    << "    &&& &&& &&& &&&\n"
			    << "       ||| |||\n"
			    << "       ||| |||\n"
			    << "       ||| |||\n"
			    << " ~ ~ ~ ~ ~ ~ ~ ~ ~\n";

	std::cout << _target + "_shrubbery" << " was delivered in your current directory, go take a look.\n" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}
