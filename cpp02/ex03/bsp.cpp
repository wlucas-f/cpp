#include "Fixed.hpp"
#include "Point.hpp"

static float calcArea(Point const a, Point const b, Point const c){
    float area((a.xFloat()*(b.yFloat()-c.yFloat())
        +b.xFloat()*(c.yFloat()-a.yFloat())
        +c.xFloat()*(a.yFloat()-b.yFloat()))/2);
    if(area < 0)
        area *= -1;
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if(point == a || point == b || point == c)
        return (false);

    float pabArea(calcArea(point, a, b));
    float pbcArea(calcArea(point, b, c));
    float pcaArea(calcArea(point, c, a));
    if(pabArea == 0 || pbcArea == 0 || pcaArea == 0)
        return false;

    float pTotalArea(pabArea + pbcArea + pcaArea);
    if (pTotalArea  > calcArea(a, b, c))
        return false;
    return true;
}
