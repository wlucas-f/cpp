#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog construtor called\n";
}

Dog::Dog(const std::string &type) : Animal(type){
    std::cout << "Dog construtor called\n";
    this->brain = new Brain();
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

Dog::~Dog(){
    std::cout << "Dog destructor called\n";
    delete brain;
}
