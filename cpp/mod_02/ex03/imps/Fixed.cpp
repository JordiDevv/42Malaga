#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Canonical implementations
Fixed::Fixed() : value(0) {}
Fixed::Fixed(const Fixed& fixed) : value(fixed.value) {}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    if (this != &fixed) this->value = fixed.value;
    return *this;
}

Fixed::~Fixed() {}

//Constructors for parameterized values
Fixed::Fixed(const int n) { value = n << fracBits; }
Fixed::Fixed(const float n) { value = roundf(n * (1 << fracBits)); }

//Getters and setters
int Fixed::getRawBits() const { return value; }
void Fixed::setRawBits(const int raw) { value = raw; }

//Getters with parsed values
float Fixed::toFloat() const { return (float)value / (1 << fracBits); }
int Fixed::toInt() const { return value >> fracBits; }

//Overload for "<<"
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

//Overload for comparisions operators
bool Fixed::operator>(const Fixed& toCompare) const { return this->value > toCompare.value; }
bool Fixed::operator<(const Fixed& toCompare) const { return this->value < toCompare.value; }
bool Fixed::operator>=(const Fixed& toCompare) const { return this->value >= toCompare.value; }
bool Fixed::operator<=(const Fixed& toCompare) const { return this->value <= toCompare.value; }
bool Fixed::operator==(const Fixed& toCompare) const { return this->value == toCompare.value; }
bool Fixed::operator!=(const Fixed& toCompare) const { return this->value != toCompare.value; }

//Overload for arithmetic operators
Fixed Fixed::operator+(const Fixed& addend) const
{
    Fixed result;
    result.value = this->value + addend.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& subtrahend) const
{
    Fixed result;
    result.value = this->value - subtrahend.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& multiplier) const
{
    Fixed result;
    result.value = (this->value * multiplier.value) >> fracBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& divisor) const
{
    Fixed result;
    result.value = (this->value << fracBits) / divisor.value;
    return result;
}

//Overload for increment and decrement operators

Fixed& Fixed::operator++()
{ value += 1; return *this; }

Fixed& Fixed::operator--()
{ value -= 1; return *this; }

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    value += 1;
    return old;
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    value -= 1;
    return old;
}

//Overloaded static function members for minimum and maximum comparatives

Fixed& Fixed::min(Fixed& a, Fixed& b) { return a < b ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{ return a < b ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return a > b ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{ return a > b ? a : b; }
