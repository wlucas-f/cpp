#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed():value(0){
            std::cout << "Default constructor called" << std::endl;
        };
        Fixed(const Fixed &obj):value(obj.value){
            std::cout << "Copy constructor called" << std::endl;
        };
        Fixed &operator=(const Fixed &obj){
            std::cout << "Copy assingment operator called" << std::endl;
            if(this == &obj)
                return *this;
            this->setRawBits(obj.getRawBits());
            return *this;
        };
        ~Fixed(){
            std::cout << "Destructor called" << std::endl;
        };
        int getRawBits(void) const{
            std::cout << "getRawBit member function called" << std::endl;
            return(this->value);
        };
        void setRawBits(int const raw){
            std::cout << "setRawBit member function called" << std::endl;
            this->value = raw;
        };
    private:
        int value;
        static const int bits = 8;
};

#endif