#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type){
    std::cout << "WrongCat construtor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
    std::cout << "WrongCat copy construtor called\n";
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
    std::cout << "WrongCat assignment operator called\n";
    if (this == &other)
        return *this;
    this->setType(other.getType());
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called\n";
}
