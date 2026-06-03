#include "Point.hpp"

Point::Point():x(0), y(0){}

Point::Point(const float x, const float y):x(x), y(y){}

Point::Point(const Point &other) : x(other.x), y(other.y){}

Point &Point::operator=(const Point &other){
    (void)other;
    return *this;
}

bool Point::operator==(const Point &other) const{
    return(this->x == other.x && this->y == other.y);
}

const Fixed Point::getX() const{
    return this->x;
}

const Fixed Point::getY() const{
    return this->y;
}

const float Point::xFloat() const{
    return (this->x.toFloat());
}

const float Point::yFloat() const{
    return (this->y.toFloat());
}

Point::~Point(){};
