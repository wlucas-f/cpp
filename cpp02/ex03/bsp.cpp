#include "Fixed.hpp"
#include "Point.hpp"

static float calcArea(Point const a, Point const b, Point const c)
{
    float area((a.getX().toFloat()*(b.getY().toFloat()-c.getY().toFloat()
        +b.getX().toFloat()*(c.getY().toFloat()-a.getY().toFloat())
        +c.getX().toFloat()*(a.getY().toFloat()-b.getY().toFloat()))/2));
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    std::cout << b.getX() << std::endl;
    std::cout << b.getY() << std::endl;
   float triangleArea(calcArea(a, b, c));
   std::cout << "triangleArea: " << triangleArea << std::endl;

   float pabArea(calcArea(point, a, b));
   std::cout << "pabArea: " << pabArea << std::endl;
   float pbcArea(calcArea(point, b, c));
   std::cout << "pbcArea: " << pbcArea << std::endl;
   float pcaArea(calcArea(point, c, a));
   std::cout << "pcaArea: " << pcaArea << std::endl;
   float pTotalArea(pabArea + pbcArea + pcaArea);
   std::cout << "pTotalArea: " << pTotalArea << std::endl;

   if (pTotalArea > triangleArea)
   {
       std::cout << "entrou\n";
       return false;
    }
   return true;
}
