#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>
#include <iostream>

int main(){

    std::cout << "\n---File Creation Test 1---\n\n";
    {
        Bureaucrat tooLow("Tolo", 150);
        ShrubberyCreationForm f("Eden");
        try{
            tooLow.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---File Creation Test 2---\n\n";
    {
        Bureaucrat writer("Escriba", 73);
        ShrubberyCreationForm f("Eden");
        Bureaucrat tooLow("Tolo", 150);
        try{
        	writer.signForm(f);
        	tooLow.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---File Creation Test 3---\n\n";
    {
        Bureaucrat writer("Escriba", 70);
        ShrubberyCreationForm f("Eden");
        try{
        	writer.signForm(f);
       		writer.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Robotomization Test 1---\n\n";
    {
        Bureaucrat tooLow("Tolo", 150);
        RobotomyRequestForm f("Felipe");
        try{
           	tooLow.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Robotomization Test 2---\n\n";
    {
        Bureaucrat writer("Escriba", 70);
        RobotomyRequestForm f("Felipe");
        Bureaucrat tooLow("Tolo", 150);
        try{
            writer.signForm(f);
           	tooLow.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Robotomization Test 3---\n\n";
    {
        Bureaucrat staff("Bocal", 41);
        RobotomyRequestForm f("Felipe");
        try{
            staff.signForm(f);
           	staff.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Presidential Pardon Test 1---\n\n";
    {
        Bureaucrat writer("Escriba", 70);
        PresidentialPardonForm f("Wallace");
        Bureaucrat tooLow("Tolo", 150);
        try{
            writer.signForm(f);
           	tooLow.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Presidential Pardon Test 2---\n\n";
    {
        Bureaucrat marvin("The Paranoid", 25);
        PresidentialPardonForm f("Wallace");
        Bureaucrat tooLow("Tolo", 150);
        try{
            marvin.signForm(f);
           	tooLow.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Presidential Test 3---\n\n";
    {
        Bureaucrat marvin("The Paranoid", 25);
        Bureaucrat president("Zaphod Beeblebrox", 1);
        PresidentialPardonForm f("Wallace");
        try{
            marvin.signForm(f);
           	president.executeForm(f);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
}
