#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog construtor called\n";
    this->brain = new Brain();
}

Dog::Dog(const std::string &type) : Animal(type){
    std::cout << "Dog construtor called\n";
    this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other){
    std::cout << "Dog copy construtor called\n";
    delete this->brain;
    this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other){
    std::cout << "Dog assignment operator called\n";
    if (this == &other)
        return *this;
    delete this->brain;
    this->brain = new Brain (*other.brain);
    return *this;
}

void Dog::makeSound (){
	std::cout << "Woof... Woof.. Woof." << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructor called\n";
    delete brain;
}
