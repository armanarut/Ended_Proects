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
    ~Fixed( void );

    Fixed& operator = ( const Fixed& other );

    Fixed operator +(const Fixed& b) const;
    Fixed operator -(const Fixed& b) const;
    Fixed operator *(const Fixed& b) const;
    Fixed operator /(const Fixed& b) const;

    bool operator >(const Fixed& b) const;
    bool operator <(const Fixed& b) const;
    bool operator >=(const Fixed& b) const;
    bool operator <=(const Fixed& b) const;
    bool operator ==(const Fixed& b) const;
    bool operator !=(const Fixed& b) const;

    Fixed& operator ++( );
    Fixed& operator --( );
    Fixed operator ++( int );
    Fixed operator --( int );

    static Fixed&  min( Fixed& a, Fixed& b );
    static Fixed&  max( Fixed& a, Fixed& b );
    static const Fixed&  min( const Fixed& a, const Fixed& b );
    static const Fixed&  max( const Fixed& a, const Fixed& b );
    float   toFloat( void ) const;
    int     toInt( void ) const;
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};

std::ostream &operator << ( std::ostream &ostream, const Fixed& other );


#endif