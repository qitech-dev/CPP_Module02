#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point &Point::operator=(const Point &other)
{
    // The exercise requires const coordinates and canonical form simultaneously.
    // Const members cannot be reassigned: Point is an immutable value object.
    (void)other;
    return *this;
}

Point::~Point(void)
{
}

const Fixed &Point::getX(void) const
{
    return _x;
}

const Fixed &Point::getY(void) const
{
    return _y;
}
