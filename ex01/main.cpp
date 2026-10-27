#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(42.42f);
	Fixed b(10);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a as int = " << a.toInt() << std::endl;

	return 0;
}
