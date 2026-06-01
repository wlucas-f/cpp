#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


int main(void)
{
    /*
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    */
    Point a(0,0);
    Point b(4,5);
    Point c(7,0);
    Point point(30, 40);
   // isInside(a, b, c, point);

   if(bsp(a, b, c, point))
       std::cout << "Point is inside the triangle: True" << std::endl;
   else
       std::cout << "Point is inside the triangle: False" << std::endl;
    return 0;
}
