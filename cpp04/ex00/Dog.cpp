#include "Dog.hpp"

Dog::Dog(std::string &type) : Animal(){
    this->type = type;
    std::cout << "Dog construtor called\n";
}

Dog::Dog(const Dog &other) : Animal(other){
    std::cout << "Dog copy construtor called\n";
    *this = other;
}

Dog &Dog::operator=(const Dog &other){
    std::cout << "Dog assignment operator called\n";
    if (this == &other)
        return *this;
    this->setType(other.getType());
    return *this;
}

void Dog::setType(const std::string &t){
    this->type = type;
}

std::string Dog::getType() const{
    return this->type;
}

Dog::~Dog(){
    std::cout << "Dog destructor called\n";
}
