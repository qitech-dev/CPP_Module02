#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
}

Point& Point::operator=(const Point& other)
{
    // Coordinates are const.
    // Assignment intentionally leaves this point unchanged.
    (void)other;
    return *this;
}

Point::~Point()
{
}

const Fixed& Point::getX(void) const
{
	return x;
}

const Fixed& Point::getY(void) const
{
	return y;
}