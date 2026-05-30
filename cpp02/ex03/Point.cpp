#include "Point.hpp"

Point::Point():x(0), y(0){}

Point::Point(const float x, const float y):x(x), y(y){}

Point::Point(Point &other){
    *this = other;
}

Point &Point::operator=(const Point &other){
    (void)other;
    return *this;
}

Point::~Point(){};
