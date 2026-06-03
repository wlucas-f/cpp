#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"


static void check(const std::string &label, bool result, bool expected)
{
    if (result == expected)
        std::cout << "  [PASS] " << label << std::endl;
    else
    {
        std::cout << "  [FAIL] " << label
                  << " (got " << (result ? "true" : "false")
                  << ", expected " << (expected ? "true" : "false") << ")"
                  << std::endl;
    }
}

int main(void)
{
    Point A(0.0f,  0.0f);
    Point B(10.0f, 0.0f);
    Point C(0.0f,  10.0f);

    std::cout << "--- Points INSIDE ---" << std::endl;
    check("(2,2)",                   bsp(A, B, C, Point(2.0f,  2.0f)),  true);
    check("(3,3)",                   bsp(A, B, C, Point(3.0f,  3.0f)),  true);
    check("(1,8)",                   bsp(A, B, C, Point(1.0f,  8.0f)),  true);

    std::cout << "--- Points OUTSIDE ---" << std::endl;
    check("Negative x (-1,5)",       bsp(A, B, C, Point(-1.0f, 5.0f)),  false);
    check("Negative y (5,-1)",       bsp(A, B, C, Point(5.0f, -1.0f)),  false);
    check("Far outside (20,20)",     bsp(A, B, C, Point(20.0f, 20.0f)), false);
    check("(8,8)",                   bsp(A, B, C, Point(8.0f,  8.0f)),  false);

    std::cout << "--- Points ON vertices (must return false) ---" << std::endl;
    check("Vertex A (0,0)",          bsp(A, B, C, Point(0.0f,  0.0f)),  false);
    check("Vertex B (10,0)",         bsp(A, B, C, Point(10.0f, 0.0f)),  false);
    check("Vertex C (0,10)",         bsp(A, B, C, Point(0.0f,  10.0f)), false);

    std::cout << "--- Points ON edges (must return false) ---" << std::endl;
    check("Midpoint AB (5,0)",       bsp(A, B, C, Point(5.0f,  0.0f)),  false);
    check("Midpoint AC (0,5)",       bsp(A, B, C, Point(0.0f,  5.0f)),  false);
    check("Midpoint BC (5,5)",       bsp(A, B, C, Point(5.0f,  5.0f)),  false);
    check("Edge AB (3,0)",           bsp(A, B, C, Point(3.0f,  0.0f)),  false);
    check("Edge AC (0,7)",           bsp(A, B, C, Point(0.0f,  7.0f)),  false);

    std::cout << std::endl;
}
