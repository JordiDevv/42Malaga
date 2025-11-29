#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Canonical implementations
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

//Overload for "<<"
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
