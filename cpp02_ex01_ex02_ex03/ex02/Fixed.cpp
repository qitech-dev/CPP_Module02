#include "Fixed.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _rawBits(value * (1 << _fractionalBits))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : _rawBits(static_cast<int>(::roundf(value * (1 << _fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(const int raw)
{
    _rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    // Division truncates toward zero; unlike signed right shift it is portable.
    return _rawBits / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}

// Compare raw values directly to avoid unnecessary conversions.
bool Fixed::operator>(const Fixed &rhs) const
{
    return _rawBits > rhs._rawBits;
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return _rawBits < rhs._rawBits;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return _rawBits >= rhs._rawBits;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return _rawBits <= rhs._rawBits;
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return _rawBits == rhs._rawBits;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return _rawBits != rhs._rawBits;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(_rawBits + rhs._rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(_rawBits - rhs._rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    if (rhs._rawBits == 0)
        throw std::domain_error("Fixed division by zero");
    return Fixed(toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void)
{
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed before(*this);
    ++_rawBits;
    return before;
}

Fixed &Fixed::operator--(void)
{
    --_rawBits;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed before(*this);
    --_rawBits;
    return before;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a <= b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a <= b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a >= b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a >= b) ? a : b;
}
