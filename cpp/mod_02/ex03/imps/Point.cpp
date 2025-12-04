#include "Point.hpp"
#include "Fixed.hpp"

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

Point::Point() : x(0), y(0) {}
Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point& Point::operator=(const Point& point)
{
    if (this != &point) new (this) Point(point);
    return *this;
}

Point::~Point() {}


   // **************************************************** //
  //        Constructors for parameterized values         //
 // **************************************************** //

Point::Point(const float x, const float y) : x(x), y(y) {}


   // **************************************************** //
  //                      Getters                         //
 // **************************************************** //

const Fixed Point::getX() const { return x; };
const Fixed Point::getY() const { return y; };