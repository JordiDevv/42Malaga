#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const Point& point);
        Point& operator=(const Point& point);
        ~Point();

        Point(const float x, const float y);
};

#endif
