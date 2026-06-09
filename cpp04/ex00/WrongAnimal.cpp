#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("WrongAnimal"){
    std::cout << "WrongAnimal default construtor called\n";
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type){
    std::cout << "WrongAnimal construtor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal copy construtor called\n";
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal assignment operator called\n";
    if (this == &other)
        return *this;
    this->setType(other.getType());
    return *this;
}

void WrongAnimal::setType(const std::string &type){
    this->type = type;
}

std::string WrongAnimal::getType() const{
    return this->type;
}

void WrongAnimal::makeSound() const{
	std::cout << "A non-defined Animal makes a generic, but weird sound!!" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called\n";
}
