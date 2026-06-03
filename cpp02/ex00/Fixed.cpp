#include "Fixed.hpp"

Fixed::Fixed():value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj):value(obj.value){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &obj){
    std::cout << "Copy assingment operator called" << std::endl;
    if(this == &obj)
        return *this;
    this->setRawBits(obj.getRawBits());
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBit member function called" << std::endl;
    return(this->value);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBit member function called" << std::endl;
    this->value = raw;
}
