#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Canonical implementations
Fixed::Fixed() : value(0)
{ std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed& fixed) : value(fixed.value)
{ std::cout << "Copy constructor called" << std::endl; }

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) this->value = fixed.value;
    return *this;
}

Fixed::~Fixed()
{ std::cout << "Destructor called" << std::endl; }

//Constructors for parameterized values
Fixed::Fixed(const int n) 
{
    std::cout << "Int constructor called" << std::endl;
    value = n << fracBits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(n * (1 << fracBits));
}

//Getters and setters
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

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
    result.value = this->value * multiplier.value;
    return result;
}

Fixed Fixed::operator/(const Fixed& divisor) const
{
    Fixed result;
    result.value = this->value / divisor.value;
    return result;
}

//Overload for increment and decrement operators

Fixed& Fixed::operator++()
{
    value += 1;
    return *this;
}

Fixed& Fixed::operator--()
{
    value -= 1;
    return *this;
}

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
