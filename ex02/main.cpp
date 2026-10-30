#include "Fixed.hpp"
#include <cassert>
#include <iostream>
#include <sstream>

int main(void)
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

    // Constructors, copy, assignment, conversions, raw bits, <<
    Fixed a;
    Fixed b(2);
    Fixed c(1.5f);
    Fixed copy(c);
    a = b;
    assert(a == b && copy == c);
    assert(b.toInt() == 2 && c.toFloat() == 1.5f);
    a.setRawBits(1);
    assert(a.getRawBits() == 1);
    std::ostringstream out;
    out << c;
    assert(out.str() == "1.5");

    // Six comparisons
    assert(b > c && c < b);
    assert(b >= c && c <= b);
    assert(b == Fixed(2) && b != c);

    // Four arithmetic operators
    assert(b + c == Fixed(3.5f));
    assert(b - c == Fixed(0.5f));
    assert(b * c == Fixed(3));
    assert(b / c == Fixed(1.33203125f));

    // Pre/post increment and decrement (one raw bit = 1/256)
    Fixed x;
    assert((++x).getRawBits() == 1);
    assert((x++).getRawBits() == 1);
    assert(x.getRawBits() == 2);
    assert((--x).getRawBits() == 1);
    assert((x--).getRawBits() == 1);
    assert(x.getRawBits() == 0);

    // min/max, mutable and const overloads
    assert(Fixed::min(b, c) == c && Fixed::max(b, c) == b);
    const Fixed d(2), e(3);
    assert(Fixed::min(d, e) == d && Fixed::max(d, e) == e);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
