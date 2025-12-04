#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
    Point a(1.0f, 2.0f);
    Point b(3.0f, 4.0f);
    Point c(5.0f, 2.0f);

    Point point(1.1f, 2.0f);

    return bsp(a, b, c, point);
}
