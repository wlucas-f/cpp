#include "Cat.hpp"

Cat::Cat(std::string &type) : Animal(&type){
    std::cout << "Cat construtor called\n";
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy construtor called\n";
    *this = other;
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat assignment operator called\n";
    if (this == &other)
        return *this;
    this->setType(other.getType());
    return *this;
}

void Cat::setType(const std::string &t){
    this->type = type;
}

std::string Cat::getType() const{
    return this->type;
}

Cat::~Cat(){
    std::cout << "Cat destructor called\n";
}
