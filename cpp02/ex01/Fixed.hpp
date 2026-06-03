#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    public:
        Fixed();
        Fixed(const int &value);
        Fixed(const float &value);
        Fixed(const Fixed &obj);
        Fixed &operator=(const Fixed &obj);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const &raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int rawValue;
        static const int fp = 8;
};

#endif
