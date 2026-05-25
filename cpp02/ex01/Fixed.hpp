#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    public:
        Fixed():rawValue(0){
            std::cout << "Default constructor called" << std::endl;
        };
        Fixed(const int &value):rawValue(value << fp){
            std::cout << "Int constructor called" << std::endl;
        };
        Fixed(const float &value):rawValue(roundf(value * (1 << fp))){
            std::cout << "Float constructor called" << std::endl;
        };
        Fixed(const Fixed &obj):rawValue(obj.rawValue){
            std::cout << "Copy constructor called" << std::endl;
        };
        Fixed &operator=(const Fixed &obj){
            std::cout << "Copy assingment operator called" << std::endl;
            if(this == &obj)
                return *this;
            this->rawValue=obj.rawValue;
            return *this;
        };
        ~Fixed(){
            std::cout << "Destructor called" << std::endl;
        };
        int getRawBits(void) const{
            std::cout << "getRawBits member function called" << std::endl;
            return(this->rawValue);
        };
        void setRawBits(int const &raw){
            std::cout << "setRawBits member function called" << std::endl;
            this->rawValue = raw;
        };
        float toFloat(void) const{
            return (float(rawValue) / float(1 << fp));
        };
        int toInt(void) const{
            return (int(rawValue) / int(1 << fp));
        };
    private:
        int rawValue;
        static const int fp = 8;
};

#endif