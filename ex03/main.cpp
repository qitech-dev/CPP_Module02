#include "Point.hpp"
#include <iostream>
#include <cassert>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	{
		Point a(0, 0);
		Point b(4, 0);
		Point c(0, 4);

		std::cout << bsp(a, b, c, Point(1, 1)) << std::endl;
		std::cout << bsp(a, b, c, Point(2, 2)) << std::endl;
		std::cout << bsp(a, b, c, Point(5, 1)) << std::endl;
	}

	{
		Point a(0, 0);
		Point b(4, 0);
		Point c(0, 4);

		assert(bsp(a, b, c, Point(1, 1)) == true);

		assert(bsp(a, b, c, Point(2, 2)) == false);

		assert(bsp(a, b, c, Point(5, 1)) == false);

		assert(bsp(a, c, b, Point(1, 1)) == true);

		float u = 1.0f / 256.0f;

		assert(bsp(
			Point(0, 0),
			Point(3 * u, 0),
			Point(0, 3 * u),
			Point(u, u)
		) == true);

		assert(bsp(
			Point(0, 0),
			Point(200, 0),
			Point(0, 200),
			Point(1, 1)
		) == true);

		std::cout << "All BSP tests passed!" << std::endl;
	}

	return 0;
}