#ifndef FIXED_HPP
#define FIXED_HPP

#include <iosfwd>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed(void);

    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    float toFloat(void) const;
    int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
