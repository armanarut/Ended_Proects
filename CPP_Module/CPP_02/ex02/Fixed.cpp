#include "Fixed.hpp"

Fixed::Fixed( void ):_raw(0)
{
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed( const int value )
{
    // std::cout << "Int constructor called\n";
    _raw = value << _fracBits;
}

Fixed::Fixed( const float value )
{
    // std::cout << "Float constructor called\n";
    _raw = round(value * (1 << _fracBits));
}

Fixed::Fixed( const Fixed& other )
{
    // std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed::~Fixed( void )
{
    // std::cout << "Destructor called\n";
}

void    Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called\n";
    this->_raw = raw;
}

int     Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called\n";
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

Fixed&  Fixed::min( Fixed& a, Fixed& b )
{
    if (a < b)
        return (a);
    return (b);
}

Fixed&  Fixed::max( Fixed& a, Fixed& b )
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed&  Fixed::min( const Fixed& a, const Fixed& b )
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed&  Fixed::max( const Fixed& a, const Fixed& b )
{
    if (a > b)
        return (a);
    return (b);
}

Fixed& Fixed::operator = ( const Fixed& other )
{
    _raw = other._raw;
    return (*this);
}

bool Fixed::operator >(const Fixed& b) const
{
    return ( _raw > b._raw);
}

bool Fixed::operator <(const Fixed& b) const
{
    return ( _raw < b._raw);
}

bool Fixed::operator >=(const Fixed& b) const
{
    return ( _raw >= b._raw);
}

bool Fixed::operator <=(const Fixed& b) const
{
    return ( _raw <= b._raw);
}

bool Fixed::operator ==(const Fixed& b) const
{
    return ( _raw == b._raw);
}

bool Fixed::operator !=(const Fixed& b) const
{
    return ( _raw != b._raw);
}

Fixed Fixed::operator +( const Fixed& b ) const
{
    Fixed _new;

    _new._raw = _raw + b._raw;
    return (_new);
}

Fixed Fixed::operator -( const Fixed& b ) const
{
    Fixed _new;

    _new._raw = _raw - b._raw;
    return (_new);
}

Fixed Fixed::operator *( const Fixed& b ) const
{
    Fixed _new(this->toFloat() * b.toFloat());

    return (_new);
}

Fixed Fixed::operator /( const Fixed& b ) const
{
    Fixed _new(this->toFloat() / b.toFloat());

    return (_new);
}

Fixed& Fixed::operator ++( )
{
    _raw++;
    return (*this);
}

Fixed& Fixed::operator --( )
{
    _raw--;
    return (*this);
}

Fixed Fixed::operator ++( int )
{
    Fixed old(*this);

    _raw++;
    return (old);
}

Fixed Fixed::operator --( int )
{
    Fixed old(*this);

    _raw--;
    return (*this);
}

std::ostream &operator << (std::ostream &os, const Fixed &other )
{
    os << other.toFloat();
    return (os);
}