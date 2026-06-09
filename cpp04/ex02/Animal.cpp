#include "Animal.hpp"
#include <string>

Animal::Animal(){};

Animal::Animal(const std::string &type) : type(type){
    std::cout << "Animal construtor called\n";
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal copy construtor called\n";
    *this = other;
}

Animal &Animal::operator=(const Animal &other){
    std::cout << "Animal assignment operator called\n";
    if (this == &other)
        return *this;
    this->setType(other.getType());
    return *this;
}

void Animal::setType(const std::string &type){
    this->type = type;
}

std::string Animal::getType() const{
    return this->type;
}

Animal::~Animal(){
    std::cout << "Animal destructor called\n";
}
