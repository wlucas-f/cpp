#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice():AMateria("ice"), type("ice"){}

Ice::Ice(const Ice &other){
    *this = other;
}

Ice &Ice::operator=(const Ice &other){
    if(this != &other)
        *this = other;
    return *this;
}

Ice::~Ice(){}

Ice* Ice::clone() const{
    Ice *newIce = new Ice;
    return newIce;
}

void use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
