#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

#define GREEN "\033[1;32m"
#define BLUE "\033[1;36m"
#define RESET "\033[0m"

int main()
{
    Point a(1.0f, 2.0f);
    Point b(3.0f, 4.0f);
    Point c(5.0f, 2.0f);

    Point point(1.1f, 1.9f);

    if (bsp(a, b, c, point))
        std::cout << GREEN << "THE POINT IS INSIDE THE TRIANGLE." << RESET << std::endl;
    else
        std::cout << BLUE << "THE POINT IS OUTSIDE THE TRIANGLE." << RESET << std::endl;

    return 0;
}
