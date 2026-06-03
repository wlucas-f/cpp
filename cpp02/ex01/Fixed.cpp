#include "Fixed.hpp"

Fixed::Fixed():rawValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &value):rawValue(value << fp){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &value):rawValue(roundf(value * (1 << fp))){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj):rawValue(obj.rawValue){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &obj){
	std::cout << "Copy assingment operator called" << std::endl;
	if(this == &obj)
		return *this;
	this->rawValue=obj.rawValue;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->rawValue);
}

void Fixed::setRawBits(int const &raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->rawValue = raw;
}

float Fixed::toFloat(void) const{
	return (float(rawValue) / float(1 << fp));
}

int Fixed::toInt(void) const{
	return (int(rawValue) / int(1 << fp));
}
