#include "Point.hpp"

Fixed GetArea(Point const p1, Point const p2, Point const p)
{
    return ((p2.getY() - p1.getY()) * (p.getX() - p1.getX())
        - (p2.getX()  - p1.getX()) * (p.getY() - p1.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed Area1 = GetArea(a, b, point);
    Fixed Area2 = GetArea(b, c, point);
    Fixed Area3 = GetArea(c, a, point);
    return (Area1 > 0 && Area2 > 0 && Area3 > 0) || (Area1 < 0 && Area2 < 0 && Area3 < 0);
}