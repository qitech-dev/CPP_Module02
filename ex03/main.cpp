#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);

	std::cout << bsp(a, b, c, Point(1, 1)) << std::endl;
	std::cout << bsp(a, b, c, Point(2, 2)) << std::endl;
	std::cout << bsp(a, b, c, Point(5, 1)) << std::endl;

    return 0;
}