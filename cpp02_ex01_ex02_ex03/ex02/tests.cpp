#include "Fixed.hpp"
#include <cassert>
#include <iostream>

int main(void)
{
    const Fixed a(3.0f);
    const Fixed b(1.5f);
    const Fixed same(3);

    // All six comparison operators.
    assert(a > b);
    assert(b < a);
    assert(a >= same);
    assert(a <= same);
    assert(a == same);
    assert(a != b);

    // All four arithmetic operators.
    assert((a + b) == Fixed(4.5f));
    assert((a - b) == Fixed(1.5f));
    assert((a * b) == Fixed(4.5f));
    assert((a / b) == Fixed(2));

    // Postfix returns the old value, prefix returns the updated reference.
    Fixed increment(0);
    assert((increment++).getRawBits() == 0);
    assert(increment.getRawBits() == 1);
    assert((++increment).getRawBits() == 2);
    assert((increment--).getRawBits() == 2);
    assert(increment.getRawBits() == 1);
    assert((--increment).getRawBits() == 0);

    Fixed x(1);
    Fixed y(2);
    const Fixed cx(1);
    const Fixed cy(2);
    assert(&Fixed::min(x, y) == &x);
    assert(&Fixed::max(x, y) == &y);
    assert(&Fixed::min(cx, cy) == &cx);
    assert(&Fixed::max(cx, cy) == &cy);

    // Non-const min/max must allow modification of the returned reference.
    Fixed::min(x, y) = Fixed(5);
    assert(x == Fixed(5));
    assert(y == Fixed(2));

    // Conversion of a negative fixed-point value truncates toward zero.
    assert(Fixed(-1.5f).toInt() == -1);
    std::cout << "All ex02 tests passed" << std::endl;
    return 0;
}
