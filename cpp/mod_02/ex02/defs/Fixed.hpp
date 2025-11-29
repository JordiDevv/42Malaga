#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int fracBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();

        Fixed(const int n);
        Fixed(const float n);

        int getRawBits() const;
        void setRawBits(const int raw);

        float toFloat() const;
        int toInt() const;

        bool operator>(const Fixed& toCompare) const;
        bool operator<(const Fixed& toCompare) const;
        bool operator>=(const Fixed& toCompare) const;
        bool operator<=(const Fixed& toCompare) const;
        bool operator==(const Fixed& toCompare) const;
        bool operator!=(const Fixed& toCompare) const;

        void operator+(const Fixed& addend);
        void operator-(const Fixed& subtrahend);
        void operator*(const Fixed& multiplier);
        void operator/(const Fixed& divisor);

        Fixed& operator++();
        Fixed& operator--();
        Fixed& operator++(int);
        Fixed& operator--(int);
    
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
