#include "Fixed.hpp"
#include <cassert>
#include <limits>
#include <stdexcept>
#include <iostream>

int main(void)
{
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

	{
		Fixed a(200);
		Fixed b(200);

		Fixed c = a * b;

		assert(c.toInt() == 40000);

		Fixed d;
		d.setRawBits(16777217);

		Fixed e = d / Fixed(1);

		assert(e.getRawBits() == 16777217);

		Fixed f = Fixed(1) / Fixed(6);

		assert(f.getRawBits() == 43);

		std::cout << "All tests passed!" << std::endl;
	}
	return 0;
}