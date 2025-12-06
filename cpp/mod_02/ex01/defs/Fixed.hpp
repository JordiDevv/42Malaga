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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
