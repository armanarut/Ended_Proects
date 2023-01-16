#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int         _raw;
    static const int   _fracBits = 8;

public:
    Fixed( void );
    Fixed( const Fixed& other );
    Fixed( const int other );
    Fixed( const float other );
    Fixed& operator = ( const Fixed& other );
    ~Fixed( void );

    float   toFloat( void ) const;
    int     toInt( void ) const;
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};

std::ostream &operator << ( std::ostream &ostream, const Fixed &other );

#endif