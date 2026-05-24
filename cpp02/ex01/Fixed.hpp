#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    public:
        Fixed():rawValue(0){
            std::cout << "Default constructor called" << std::endl;
        };
        Fixed(const int &value):rawValue(value << 8){
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
            this->setRawBits(obj.getRawBits());
            return *this;
        };
        ~Fixed(){
            std::cout << "Destructor called" << std::endl;
        };
        int getRawBits(void) const{
            return(this->rawValue);
        };
        void setRawBits(int const &raw){
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