#pragma once
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed  x;
    const Fixed  y;

public:
    Point( void );
    Point( const float x1, const float y1 );
    Point( const Fixed& x1, const Fixed& y1 );
    Point( const Point&  copy);
    ~Point( void );

    float getX( void ) const;
    float getY( void ) const;
    Point& operator =(const Point& copy);
    bool operator ==(const Point& b) const;

};

#endif