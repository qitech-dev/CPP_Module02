#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	const int scale = 1 << _fractionalBits;
	const int minInt = std::numeric_limits<int>::min();
	const int maxInt = std::numeric_limits<int>::max();

	if (value < minInt / scale || value > maxInt / scale)
		throw std::overflow_error("Fixed integer construction overflow");
	
	_rawBits = value * scale;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	const double minRaw = std::numeric_limits<int>::min();
	const double maxRaw = std::numeric_limits<int>::max();
	const double scaledValue = static_cast<double>(value) * (1 << _fractionalBits);

	if (!(scaledValue >= minRaw - 0.5 && scaledValue <= maxRaw + 0.5))
		throw std::overflow_error("Fixed float construction out of range");

	const double raw = roundf(static_cast<float>(scaledValue));

	if (!(raw >= minRaw && raw <= maxRaw))
		throw std::overflow_error("Fixed float construction overflow");

	_rawBits = static_cast<int>(raw);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = other._rawBits;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _rawBits / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
	os << value.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_rawBits != other._rawBits);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	const int a = _rawBits;
	const int b = other._rawBits;
	const int maxInt = std::numeric_limits<int>::max();
	const int minInt = std::numeric_limits<int>::min();

	if ((b > 0 && a > maxInt - b) || (b < 0 && a < minInt - b))
		throw std::overflow_error("Fixed addition overflow");

	Fixed result;
	result.setRawBits(a + b);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	const int a = _rawBits;
	const int b = other._rawBits;
	const int maxInt = std::numeric_limits<int>::max();
	const int minInt = std::numeric_limits<int>::min();

	if ((b > 0 && a < minInt + b) || (b < 0 && a > maxInt + b))
		throw std::overflow_error("Fixed subtraction overflow");

	Fixed result;
	result.setRawBits(a - b);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	long product = static_cast<long>(_rawBits) * other._rawBits;
	long raw = product / (1L << _fractionalBits);

	if (raw > std::numeric_limits<int>::max()
		|| raw < std::numeric_limits<int>::min())
		throw std::overflow_error("Fixed multiplication overflow");
	
	Fixed result;
	result.setRawBits(static_cast<int>(raw));

	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other._rawBits == 0)
		throw std::domain_error("Division by zero");

	long numerator = static_cast<long>(_rawBits) * (1L << _fractionalBits);

	long denominator = other._rawBits;

	long quotient = numerator / denominator;
	long remainder = numerator % denominator;

	long absRem = remainder < 0 ? -remainder : remainder;
	long absDen = denominator < 0 ? -denominator : denominator;

	if (2 * absRem >= absDen)
	{
		if ((numerator < 0) != (denominator < 0))
			quotient--;
		else
			quotient++;
	}

	if (quotient > std::numeric_limits<int>::max()
		|| quotient < std::numeric_limits<int>::min())
		throw std::overflow_error("Fixed division pverflow");
	
	Fixed result;
	result.setRawBits(static_cast<int>(quotient));

	return result;
}

Fixed& Fixed::operator++()
{
	if (_rawBits == std::numeric_limits<int>::max())
		throw std::overflow_error("Fixed increment overflow");

	++_rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	++(*this);
	return old;
}

Fixed& Fixed::operator--()
{
	if (_rawBits == std::numeric_limits<int>::min())
		throw std::overflow_error("Fixed decrement overflow");

	--_rawBits;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	--(*this);
	return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}