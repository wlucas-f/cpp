#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	    Fixed();
	    Fixed(const int &value);
	    Fixed(const float &value);
	    Fixed(const Fixed &obj);
	    Fixed &operator=(const Fixed &obj);
	    Fixed operator+(const Fixed &obj);
	    Fixed operator-(const Fixed &obj);
	    Fixed operator*(const Fixed &obj);
	    Fixed operator/(const Fixed &obj);
	    bool operator>(const Fixed &obj) const;
	    bool operator<(const Fixed &obj) const;
	    bool operator>=(const Fixed &obj) const;
	    bool operator<=(const Fixed &obj) const;
	    bool operator==(const Fixed &obj) const;
	    bool operator!=(const Fixed &obj) const;
	    Fixed& operator++();
	    Fixed operator++(int);
	    Fixed& operator--();
	    Fixed operator--(int);
	    static Fixed& max(Fixed &a, Fixed& b);
	    static const Fixed& max(const Fixed &a, const Fixed& b);
	    static Fixed& min(Fixed &a, Fixed& b);
	    static const Fixed& min(const Fixed &a, const Fixed& b);
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
