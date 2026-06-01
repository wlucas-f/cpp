#include "Fixed.hpp"
#include "Point.hpp"

static Fixed calcArea(Point const a, Point const b, Point const c)
{
    Fixed aX(a.getX());
    Fixed aY(a.getY());
    Fixed bX(b.getX());
    Fixed bY(b.getY());
    Fixed cX(c.getX());
    Fixed cY(c.getY());

    Fixed A((aX*(bY-cY)+bX*(cY-aY)+cX*(aY-bY))/2);
    return (A);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    std::cout << b.getX() << std::endl;
    std::cout << b.getY() << std::endl;
   Fixed triangleArea(calcArea(a, b, c));
   std::cout << "triangleArea: " << triangleArea << std::endl;

   Fixed pabArea(calcArea(point, a, b));
   std::cout << "pabArea: " << pabArea << std::endl;
   Fixed pbcArea(calcArea(point, b, c));
   std::cout << "pbcArea: " << pbcArea << std::endl;
   Fixed pcaArea(calcArea(point, c, a));
   std::cout << "pcaArea: " << pcaArea << std::endl;
   Fixed pTotalArea(pabArea + pbcArea + pcaArea);
   std::cout << "pTotalArea: " << pTotalArea << std::endl;

   if (pTotalArea > triangleArea)
   {
       std::cout << "entrou\n";
       return false;
    }
   return true;
}
