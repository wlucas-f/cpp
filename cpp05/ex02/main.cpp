#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>
#include <iostream>

int main(){

    std::cout << "---File Creation Test 1---\n\n";
    {
        Bureaucrat tooLow("Tolo", 150);
        ShrubberyCreationForm f("Eden");
        try{
            f.execute(tooLow);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---File Creation Test 2---\n\n";
    {
        Bureaucrat writer("Escriba", 73);
        ShrubberyCreationForm f("Eden");
        writer.signForm(f);
        Bureaucrat tooLow("Tolo", 150);
        try{
            f.execute(tooLow);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---File Creation Test 3---\n\n";
    {
        Bureaucrat writer("Escriba", 70);
        ShrubberyCreationForm f("Eden");
        writer.signForm(f);
        try{
            f.execute(writer);
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
            f.execute(tooLow);
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
            f.execute(tooLow);
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
            f.execute(staff);
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
            f.execute(tooLow);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Presidential Pardon Test 2---\n\n";
    {
        Bureaucrat Marvin("The Paranoid", 25);
        PresidentialPardonForm f("Wallace");
        Bureaucrat tooLow("Tolo", 150);
        try{
            Marvin.signForm(f);
            f.execute(tooLow);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "---Presidential Test 3---\n\n";
    {
        Bureaucrat Marvin("The Paranoid", 25);
        Bureaucrat President("Zaphod Beeblebrox", 1);
        PresidentialPardonForm f("Wallace");
        try{
            Marvin.signForm(f);
            f.execute(President);
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    /*
        std::cout << "---Out of range constructor 1---\n\n";
        {
        try{
        AForm indepedenceLetter("Independence Letter", false, 0, 0);
        }catch (std::exception &e){
        std::cout << e.what() << std::endl;
        }
        }
        std::cout << std::endl << std::endl;

        std::cout << "---Out of range constructor 2---\n\n";
        {
        try{
        AForm tissue("Tissue", false, 151, 151);
        }catch (std::exception &e){
        std::cout << e.what() << std::endl;
        }
        }
        std::cout << std::endl << std::endl;

        std::cout << "---Insertion operator Overload---\n\n";
        {
        AForm f("FAAAAA!", false, 76, 75);
        std::cout << f;
        }
        std::cout << std::endl << std::endl;

        std::cout << "---Lower rank bureaucrat tries to sign---\n\n";
        {
        Bureaucrat tooLow("Tolo", Bureaucrat::lowestGrade);
        std::cout << tooLow;

        AForm googleAForms("Google AForms", false, 140, 140);
        std::cout << googleAForms << std::endl << std::endl;

        try{
        tooLow.signForm(googleAForms);
        }catch(std::exception &e){
        std::cout << e.what() << std::endl;
        }
        }
        std::cout << std::endl << std::endl;
        */
}
