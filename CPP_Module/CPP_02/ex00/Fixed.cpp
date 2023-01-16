#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ):_raw(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called\n";
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";
    this->_raw = raw;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return (_raw);
}

Fixed::Fixed( const Fixed &other )
{
    std::cout << "Copy constructor called\n";
    _raw = other.getRawBits();
}

Fixed & Fixed::operator = ( const Fixed &other )
{
    std::cout << "Copy assignment operator called\n";
    _raw = other.getRawBits();
    return (*this);
}