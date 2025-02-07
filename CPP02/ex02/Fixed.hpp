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

    // declaring the overloaded operators. Works with this Fixed object and other Fixed object that is input
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++();   // Pre-increment (increase before use)
    Fixed operator++(int); // Post-increment (increase after use)
    Fixed &operator--();   // Pre-decrement
    Fixed operator--(int); // Post-decrement

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits(void) const;

    /*Why static: They don’t belong to a single object, they work on two objects.
    Static functions don’t need an instance of Fixed to be called.
    Called directly using Fixed::min(a, b) instead of a.min(b).*/
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif


