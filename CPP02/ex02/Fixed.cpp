#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0){}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if(this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int intValue) {
    this->_rawBits = intValue << _fractionalBits; // Shift left by 8 bits means multiply by 256. Ex: 10 << 8 becomes 2660
}

Fixed::Fixed(const float floatValue) {
    this->_rawBits = roundf(floatValue * (1 << _fractionalBits)); // multiplies by 256 and rounds: Ex: 42.42 * 256 is rounded and stored.
}

float Fixed::toFloat(void) const {
    return(float)this->_rawBits / (1 << _fractionalBits); //divide by 256
}

int Fixed::toInt(void) const {
    return this->_rawBits >>_fractionalBits; // Shift right to remove fraction: 
}

bool Fixed::operator>(const Fixed &other) const {return this->_rawBits > other._rawBits;}
bool Fixed::operator<(const Fixed &other) const {return this->_rawBits < other._rawBits;}
bool Fixed::operator>=(const Fixed &other) const {return this->_rawBits >= other._rawBits;}
bool Fixed::operator<=(const Fixed &other) const {return this->_rawBits <= other._rawBits;}
bool Fixed::operator==(const Fixed &other) const {return this->_rawBits == other._rawBits;}
bool Fixed::operator!=(const Fixed &other) const {return this->_rawBits != other._rawBits;}

Fixed Fixed::operator+(const Fixed &other) const {return Fixed(this->toFloat() + other.toFloat());}
Fixed Fixed::operator-(const Fixed &other) const {return Fixed(this->toFloat() - other.toFloat());}
Fixed Fixed::operator*(const Fixed &other) const {return Fixed(this->toFloat() * other.toFloat());}
Fixed Fixed::operator/(const Fixed &other) const {return Fixed(this->toFloat() / other.toFloat());}

Fixed &Fixed::operator++(){
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp = *this;
    this->_rawBits++;
    return temp;
}

Fixed &Fixed::operator--(){
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->_rawBits--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { 
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int Fixed::getRawBits(void) const {
    return this->_rawBits;
}
// This calls toFloat(), which converts the Fixed number back to a float, so that std::cout prints a readable decimal number.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();  // Print as float
    return out; // 
}

