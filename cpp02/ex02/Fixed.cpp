#include "Fixed.hpp"

// Constructors
Fixed::Fixed() : rawValue(0) {}

Fixed::Fixed(const int &value) : rawValue(value << 8) {}

Fixed::Fixed(const float &value) : rawValue(roundf(value * (1 << fp))) {}

Fixed::Fixed(const Fixed &obj) : rawValue(obj.rawValue) {}

// Operators
Fixed &Fixed::operator=(const Fixed &obj){
    if (this == &obj)
        return *this;
    this->rawValue = obj.rawValue;
    return *this;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &obj){
    return (this->rawValue + obj.rawValue);
}

Fixed Fixed::operator-(const Fixed &obj){
    return (this->rawValue - obj.rawValue);
}

Fixed Fixed::operator*(const Fixed &obj){
    Fixed ret;
    int64_t v1(this->rawValue * obj.rawValue);
    ret.setRawBits(v1 >> fp);
    return (ret);
}

Fixed Fixed::operator/(const Fixed &obj){
    Fixed ret;
    int64_t v1(this->rawValue);
    int64_t v2(obj.rawValue);
    ret.setRawBits((v1 << fp) / v2);
    return (ret);
}

// Comparison Operators
bool Fixed::operator>(const Fixed &obj) const{
    return (this->rawValue > obj.rawValue);
}

bool Fixed::operator<(const Fixed &obj) const{
    return (this->rawValue < obj.rawValue);
}

bool Fixed::operator>=(const Fixed &obj) const{
    return (this->rawValue >= obj.rawValue);
}

bool Fixed::operator<=(const Fixed &obj) const{
    return (this->rawValue <= obj.rawValue);
}

bool Fixed::operator==(const Fixed &obj) const{
    return (this->rawValue == obj.rawValue);
}

bool Fixed::operator!=(const Fixed &obj) const{
    return (this->rawValue != obj.rawValue);
}

// Increment/decrement
Fixed &Fixed::operator++(){
    this->rawValue++;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed copy(*this);
    ++(*this);
    return (copy);
}

Fixed &Fixed::operator--(){
    this->rawValue--;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed copy(*this);
    ++(*this);
    return (copy);
}

// Destructor
Fixed::~Fixed(){};

// Member functions - getters & setters
int Fixed::getRawBits(void) const{
    return (this->rawValue);
}

void Fixed::setRawBits(int const &raw){
    this->rawValue = raw;
}

// Member functions - conversions
float Fixed::toFloat(void) const{
    return (float(rawValue) / float(1 << fp));
}

int Fixed::toInt(void) const{
    return (int(rawValue) / int(1 << fp));
}

// Overloaded member functions
Fixed& Fixed::max(Fixed &a, Fixed &b){
    return(a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
    return(a > b ? a : b);
}

Fixed& min(Fixed &a, Fixed& b){
    return(a < b ? a : b);
}

const Fixed& min(const Fixed &a, const Fixed& b){
    return(a < b ? a : b);
}
