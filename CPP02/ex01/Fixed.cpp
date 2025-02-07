#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Distructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = intValue << _fractionalBits; // Shift left by 8 bits means multiply by 256. Ex: 10 << 8 becomes 2660
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(floatValue * (1 << _fractionalBits)); // multiplies by 256 and rounds: Ex: 42.42 * 256 is rounded and stored.
}

float Fixed::toFloat(void) const {
    return(float)this->_rawBits / (1 << _fractionalBits); //divide by 256
}

int Fixed::toInt(void) const {
    return this->_rawBits >>_fractionalBits; // Shift right to remove fraction: 
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}
// This calls toFloat(), which converts the Fixed number back to a float, so that std::cout prints a readable decimal number.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();  // Print as float
    return out; // 
}
