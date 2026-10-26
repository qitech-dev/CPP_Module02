#include "bsp.hpp"

#include <cassert>
#include <iostream>

int main(void)
{
    const Point a(0.0f, 0.0f);
    const Point b(10.0f, 0.0f);
    const Point c(0.0f, 10.0f);

    assert(bsp(a, b, c, Point(1.0f, 1.0f)));      // Strictly inside
    assert(!bsp(a, b, c, Point(7.0f, 7.0f)));     // Outside
    assert(!bsp(a, b, c, Point(0.0f, 5.0f)));     // Edge AC
    assert(!bsp(a, b, c, Point(5.0f, 0.0f)));     // Edge AB
    assert(!bsp(a, b, c, Point(5.0f, 5.0f)));     // Edge BC
    assert(!bsp(a, b, c, a));                    // Vertex A
    assert(bsp(c, b, a, Point(1.0f, 1.0f)));      // Reverse winding

    const Point d(-10.0f, -10.0f);
    const Point e(10.0f, -10.0f);
    const Point f(0.0f, 10.0f);
    assert(bsp(d, e, f, Point(0.0f, 0.0f)));      // Negative coordinates

    const Point collinear(5.0f, 0.0f);
    assert(!bsp(a, b, collinear, Point(1.0f, 1.0f))); // Degenerate triangle

    // Very small triangle: avoid quantizing signed areas to 1/256.
    const Point tinyA(0.0f, 0.0f);
    const Point tinyB(3.0f / 256.0f, 0.0f);
    const Point tinyC(0.0f, 3.0f / 256.0f);
    assert(bsp(tinyA, tinyB, tinyC, Point(1.0f / 256.0f, 1.0f / 256.0f)));
    assert(!bsp(tinyA, tinyB, tinyC, Point(2.0f / 256.0f, 1.0f / 256.0f)));

    std::cout << "All ex03 BSP tests passed" << std::endl;
    return 0;
}
