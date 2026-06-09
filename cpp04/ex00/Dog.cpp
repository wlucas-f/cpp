#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog():Animal("Dog"){
    std::cout << "Dog default construtor called\n";
}

Dog::Dog(const std::string &type) : Animal(type){
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

void Dog::makeSound() const{
   std::cout << "Woof... Woof.. Woof!" << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructor called\n";
}
