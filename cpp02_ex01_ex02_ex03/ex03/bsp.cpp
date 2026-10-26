#include "bsp.hpp"

// Signed cross product (B - A) x (P - A).
// Using double avoids another fixed-point rounding step for the area.
static double cross(const Point &a, const Point &b, const Point &p)
{
    const double ax = a.getX().toFloat();
    const double ay = a.getY().toFloat();
    const double bx = b.getX().toFloat();
    const double by = b.getY().toFloat();
    const double px = p.getX().toFloat();
    const double py = p.getY().toFloat();

    return (bx - ax) * (py - ay) - (by - ay) * (px - ax);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    const double ab = cross(a, b, point);
    const double bc = cross(b, c, point);
    const double ca = cross(c, a, point);

    // Strict inequalities exclude points on edges and vertices.
    return (ab > 0 && bc > 0 && ca > 0)
        || (ab < 0 && bc < 0 && ca < 0);
}
