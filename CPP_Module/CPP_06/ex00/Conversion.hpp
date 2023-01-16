#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <string>
#include <limits.h>
#include <cmath>

class Conversion
{
private:
    double  value;
    bool    err;

    void to_char();
    void to_int();
    void to_float();
    void to_double();
public:
    Conversion ( void ) {};
    Conversion ( const std::string str );
    Conversion ( const Conversion& other );
    Conversion& operator =(const Conversion& other);
    ~Conversion ( void ) {};


}; 

#endif