#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat construtor called\n";
    this->brain = new Brain();
}

Cat::Cat(const std::string &type) : Animal(type){
    std::cout << "Cat construtor called\n";
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy construtor called\n";
    delete this->brain;
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat assignment operator called\n";
    if (this == &other)
        return *this;
    delete this->brain;
    this->brain = new Brain(*other.brain);
    return *this;
}

void Cat::makeSound (){
	std::cout << "Meoww... Meoww.. Meow." << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat destructor called\n";
    delete brain;
}
