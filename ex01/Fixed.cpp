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