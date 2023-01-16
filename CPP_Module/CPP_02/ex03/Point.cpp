#include "Point.hpp"

Point::Point( void ):x(Fixed()), y(Fixed())
{
}

Point::Point( const float x1, const float y1 ):x(Fixed(x1)), y(Fixed(y1))
{
}

Point::Point( const Fixed& x1, const Fixed& y1 ):x(x1), y(y1)
{
}

Point::Point( const Point&  copy):x(copy.x), y(copy.y)
{
}

Point::~Point( void )
{
}

Point& Point::operator =(const Point& copy)
{
    (void)copy;
    return (*this);
}

float Point::getX( void ) const
{
    return (this->x.toFloat());
}

float Point::getY( void ) const
{
    return (this->y.toFloat());
}

bool Point::operator ==(const Point& b) const
{
    return (b.x == x && b.y == y);
}
