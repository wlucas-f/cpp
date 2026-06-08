#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure():AMateria("cure"), type("cure"){}

Cure::Cure(const Cure &other){
    *this = other;
}

Cure &Cure::operator=(const Cure &other){
    if(this != &other)
        *this = other;
    return *this;
}

Cure::~Cure(){}

Cure* Cure::clone() const{
    Cure *newCure = new Cure;
    return newCure;
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
