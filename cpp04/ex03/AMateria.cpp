#include "AMateria.hpp"
#include "iostream"

AMateria::AMateria():type("Default"){}

AMateria::AMateria(std::string const & type):type(type){}

AMateria::AMateria(const AMateria &other){
    *this = other;
}

AMateria& AMateria::operator=(const AMateria &other){
   if(this != &other)
       *this = other;
   return *this;
}

AMateria::~AMateria(){}

std::string const &AMateria::getType() const{ //Returns the materia type
    return this->type;
}

void AMateria::use(ICharacter& target){
    std::cout << "* uses A Materia at " << target.getName() << " *\n";
}
