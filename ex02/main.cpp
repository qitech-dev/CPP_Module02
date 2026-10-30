#include "Fixed.hpp"
#include <cassert>
#include <limits>
#include <stdexcept>

static void testFixed()
{
    Fixed a(-2), b(3), same(-2);

    // 六种比较运算，包括相等情况
    assert(a < b && !(a > b));
    assert(b > a && !(b < a));
    assert(a <= same && a >= same);
    assert(!(a >= b) && !(b <= a));
    assert(a == same && !(a != same));
    assert(a != b && !(a == b));

    // 四则运算
    assert(a + b == Fixed(1));
    assert(a - b == Fixed(-5));
    assert(a * b == Fixed(-6));
    assert(b / a == Fixed(-1.5f));

    // 前置返回自身引用，后置返回修改前的值
    Fixed n;
    assert(&(++n) == &n && n.getRawBits() == 1);
    assert((n++).getRawBits() == 1);
    assert(n.getRawBits() == 2);
    assert(&(--n) == &n && n.getRawBits() == 1);
    assert((n--).getRawBits() == 1);
    assert(n.getRawBits() == 0);

    // 四个 min/max 重载，检查返回的是原对象
    assert(&Fixed::min(a, b) == &a);
    assert(&Fixed::max(a, b) == &b);

    const Fixed ca(a), cb(b);
    assert(&Fixed::min(ca, cb) == &ca);
    assert(&Fixed::max(ca, cb) == &cb);

    // 整数构造越界
    bool caught = false;
    try
    {
        (void)Fixed(std::numeric_limits<int>::max());
    }
    catch (const std::overflow_error&)
    {
        caught = true;
    }
    assert(caught);

    // 自增越界时，原对象应保持原值
    n.setRawBits(std::numeric_limits<int>::max());
    caught = false;
    try
    {
        ++n;
    }
    catch (const std::overflow_error&)
    {
        caught = true;
    }
    assert(caught);
    assert(n.getRawBits() == std::numeric_limits<int>::max());
}

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