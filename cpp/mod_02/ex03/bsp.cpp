#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
        (point.getX() == b.getX() && point.getY() == b.getY()) ||
        (point.getX() == c.getX() && point.getY() == c.getY()))
            return false;
    return true;
}
