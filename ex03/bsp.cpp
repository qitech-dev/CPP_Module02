#include "Point.hpp"

static long double cross(const Point& a,const Point& b, const Point& p)
{
	long double abx = static_cast<long double>(b.getX().getRawBits()) - a.getX().getRawBits();

	long double aby = static_cast<long double>(b.getY().getRawBits()) - a.getY().getRawBits();

	long double apx = static_cast<long double>(p.getX().getRawBits()) - a.getX().getRawBits();

	long double apy = static_cast<long double>(p.getY().getRawBits()) - a.getY().getRawBits();

	return abx * apy - aby * apx;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	long double c1 = cross(a, b, point);
	long double c2 = cross(b, c, point);
	long double c3 = cross(c, a, point);

	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0))
		return true;
	
	return false;
}