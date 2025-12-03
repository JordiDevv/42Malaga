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

        Fixed operator+(const Fixed& addend) const;
        Fixed operator-(const Fixed& subtrahend) const;
        Fixed operator*(const Fixed& multiplier) const;
        Fixed operator/(const Fixed& divisor) const;

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
    
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
