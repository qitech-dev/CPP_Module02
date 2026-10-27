#include "Point.hpp"

static Fixed cross(const Point& a,const Point& b, const Point& p)
{
	return (b.getX() - a.getX())*(p.getY() - a.getY()) - (b.getY() - a.getY())*(p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed c1 = cross(a, b, point);
	Fixed c2 = cross(b, c, point);
	Fixed c3 = cross(c, a, point);

	Fixed zero(0);

	if ((c1 > zero && c2 > zero && c3 > zero)
		|| (c1 < zero && c2 < zero && c3 < zero))
		return true;
	return false;
}