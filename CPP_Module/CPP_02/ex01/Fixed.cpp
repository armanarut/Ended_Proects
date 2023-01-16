#include "Fixed.hpp"

Fixed::Fixed( void ):_raw(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed( const int value )
{
    std::cout << "Int constructor called\n";
    _raw = value << _fracBits;
}

Fixed::Fixed( const float value )
{
    std::cout << "Float constructor called\n";
    _raw = round(value * (1 << _fracBits));
}

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called\n";
    *this = other;
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

float   Fixed::toFloat( void ) const
{
    return ((float)_raw / (1 << _fracBits));
}

int   Fixed::toInt( void ) const
{
    return (_raw >> _fracBits);
}

Fixed& Fixed::operator = ( const Fixed& other )
{
    std::cout << "Copy assignment operator called\n";
    _raw = other._raw;
    return (*this);
}

std::ostream &operator << (std::ostream &os, const Fixed &other )
{
    os << other.toFloat();
    return (os);
}