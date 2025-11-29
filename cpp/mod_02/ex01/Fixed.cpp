#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0)
{ std::cout << "Default constructor called" << std::endl; }
Fixed::Fixed(const Fixed& fixed) : value(fixed.value)
{ std::cout << "Copy assignment operator called" << std::endl; }
Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) this->value = fixed.value;
    return *this;
}
Fixed::~Fixed()
{ std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const int n) 
{
    std::cout << "Int constructor called" << std::endl;
    value = n << fracBits;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
};
void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
};

float Fixed::toFloat() const { return (float)value / (1 << fracBits); }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
