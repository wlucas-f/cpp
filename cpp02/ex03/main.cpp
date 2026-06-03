#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

// Simple test helper
static int g_passed = 0;
static int g_failed = 0;

static void check(const std::string &label, bool result, bool expected)
{
    if (result == expected)
    {
        std::cout << "  [PASS] " << label << std::endl;
        g_passed++;
    }
    else
    {
        std::cout << "  [FAIL] " << label
                  << " (got " << (result ? "true" : "false")
                  << ", expected " << (expected ? "true" : "false") << ")"
                  << std::endl;
        g_failed++;
    }
}

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    // Triangle used for most tests: (0,0) (10,0) (0,10)
    Point A(0.0f,  0.0f);
    Point B(10.0f, 0.0f);
    Point C(0.0f,  10.0f);

    std::cout << "--- Points clearly INSIDE ---" << std::endl;
    check("Center-ish (1,1)",        bsp(A, B, C, Point(1.0f,  1.0f)),  true);
    check("(2,2)",                   bsp(A, B, C, Point(2.0f,  2.0f)),  true);
    check("(3,3)",                   bsp(A, B, C, Point(3.0f,  3.0f)),  true);
    check("(1,8)",                   bsp(A, B, C, Point(1.0f,  8.0f)),  true);
    check("(8,1)",                   bsp(A, B, C, Point(8.0f,  1.0f)),  true);
    check("Very close to centroid",  bsp(A, B, C, Point(3.3f,  3.3f)),  true);

    std::cout << "--- Points clearly OUTSIDE ---" << std::endl;
    check("Negative x (-1,5)",       bsp(A, B, C, Point(-1.0f, 5.0f)),  false);
    check("Negative y (5,-1)",       bsp(A, B, C, Point(5.0f, -1.0f)),  false);
    check("Far outside (20,20)",     bsp(A, B, C, Point(20.0f, 20.0f)), false);
    check("Beyond hypotenuse (6,6)", bsp(A, B, C, Point(6.0f,  6.0f)),  false);
    check("(8,8)",                   bsp(A, B, C, Point(8.0f,  8.0f)),  false);
    check("Opposite quadrant (-5,-5)",bsp(A, B, C, Point(-5.0f,-5.0f)), false);

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

    std::cout << "--- Different triangle: equilateral-ish (0,0)(6,0)(3,5) ---" << std::endl;
    Point D(0.0f, 0.0f);
    Point E(6.0f, 0.0f);
    Point F(3.0f, 5.0f);
    check("Centroid (3,1.6) inside",  bsp(D, E, F, Point(3.0f,  1.6f)),  true);
    check("(1,1) inside",             bsp(D, E, F, Point(1.0f,  1.0f)),  true);
    check("(5,1) inside",             bsp(D, E, F, Point(5.0f,  1.0f)),  true);
    check("(3,4) inside",             bsp(D, E, F, Point(3.0f,  4.0f)),  true);
    check("(0,5) outside",            bsp(D, E, F, Point(0.0f,  5.0f)),  false);
    check("(-1,0) outside",           bsp(D, E, F, Point(-1.0f, 0.0f)),  false);
    check("Vertex D (0,0)",           bsp(D, E, F, Point(0.0f,  0.0f)),  false);
    check("Vertex F (3,5)",           bsp(D, E, F, Point(3.0f,  5.0f)),  false);

    std::cout << "--- Triangle with negative coords (-5,-5)(5,-5)(0,5) ---" << std::endl;
    Point G(-5.0f, -5.0f);
    Point H(5.0f,  -5.0f);
    Point I(0.0f,   5.0f);
    check("(0,0) inside",             bsp(G, H, I, Point(0.0f,  0.0f)),  true);
    check("(0,-3) inside",            bsp(G, H, I, Point(0.0f, -3.0f)),  true);
    check("(0,4) inside",             bsp(G, H, I, Point(0.0f,  4.0f)),  true);
    check("(10,0) outside",           bsp(G, H, I, Point(10.0f, 0.0f)),  false);
    check("(0,-6) outside",           bsp(G, H, I, Point(0.0f, -6.0f)),  false);
    check("Vertex G (-5,-5)",         bsp(G, H, I, Point(-5.0f,-5.0f)),  false);

    std::cout << std::endl;
    std::cout << "Results: " << g_passed << " passed, " << g_failed << " failed." << std::endl;

    return (g_failed > 0 ? 1 : 0);
}
