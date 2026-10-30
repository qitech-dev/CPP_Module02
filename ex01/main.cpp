#include "Fixed.hpp"
#include <cassert>
#include <iostream>
#include <sstream>

int main(void)
{
	{
		Fixed a(42.42f);
		Fixed b(10);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "a as int = " << a.toInt() << std::endl;
	}
	
	{
		// Default constructor, getRawBits, setRawBits
		Fixed a;
		assert(a.getRawBits() == 0);
		a.setRawBits(128);
		assert(a.toFloat() == 0.5f);

		// Int constructor
		Fixed b(10);
		assert(b.toInt() == 10);

		// Float constructor and conversions
		Fixed c(42.42f);
		assert(c.getRawBits() == 10860);
		assert(c.toFloat() == 42.421875f);
		assert(c.toInt() == 42);

		// Copy constructor
		Fixed copy(c);
		assert(copy.getRawBits() == c.getRawBits());

		// Assignment operator
		a = b;
		assert(a.getRawBits() == b.getRawBits());

		// Output operator <<
		std::ostringstream out;
		out << c;
		assert(out.str() == "42.4219");

		std::cout << "All tests passed!" << std::endl;
		return 0;
	}
}
