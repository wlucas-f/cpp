#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
 public:
    Point();
    Point(const float x, const float y);
    Point(const Point &point);
    Point& operator=(const Point &point);
    const Fixed getX() const;
    const Fixed getY() const;
    ~Point();
 private:
     const Fixed x;
     const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
