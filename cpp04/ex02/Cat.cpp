#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << "Cat construtor called\n";
    this->brain = new Brain();
}

Cat::Cat(const std::string &type) : Animal(type){
    std::cout << "Cat construtor called\n";
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy construtor called\n";
    if (this != &other)
    	this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat assignment operator called\n";
    if (this != &other){
    	delete this->brain;
    	this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const{
	std::cout << "Meoww... Meoww.. Meow." << std::endl;
}

Brain* Cat::getBrain(){
    return this->brain;
}

Cat::~Cat(){
    std::cout << "Cat destructor called\n";
    delete this->brain;
}
