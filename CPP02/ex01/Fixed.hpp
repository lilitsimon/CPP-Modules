#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other); // Copy constructor
    Fixed &operator=(const Fixed &other);// Copy assignment operator
    ~Fixed();

    Fixed(const int intValue);
    Fixed(const float floatValue);

    float toFloat(void) const;
    int toInt(void)const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed); // overaloading the << operator

#endif

