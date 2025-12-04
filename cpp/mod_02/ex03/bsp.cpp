#include "Point.hpp"

static Fixed sign(const Point& p, const Point& a, const Point& b)
{ return (p.getX() - b.getX()) * (a.getY() - b.getY()) - (a.getX() - b.getX()) * (p.getY() - b.getY()); }

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
        (point.getX() == b.getX() && point.getY() == b.getY()) ||
        (point.getX() == c.getX() && point.getY() == c.getY()))
            return false;

    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    bool hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return !(hasNeg && hasPos);
}
