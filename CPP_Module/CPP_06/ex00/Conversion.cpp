#include "Conversion.hpp"


Conversion::Conversion( const std::string str )
{
    try {
        this->value = stod(str);
    }
    catch ( const std::exception) {
        this->err = 1;
    }

    std::cout << std::fixed;
    std::cout.precision(1);
    to_char();
    to_int();
    to_float();
    to_double();
}

void Conversion::to_char()
{   
    if (err || isnan(value) || value > CHAR_MAX || value < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(value))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(this->value) << "'" << std::endl;
}

void Conversion::to_int()
{
    if (err || isnan(value) || value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
	    std::cout << "int: " << static_cast<int>(this->value) << std::endl;
}

void Conversion::to_float()
{
    if (err)
        std::cout << "float: impossible" << std::endl;
    else 
        std::cout << "float: " << static_cast<float>(this->value) << "f" << std::endl;
}

void Conversion::to_double()
{
    if (err)
        std::cout << "double: impossible" << std::endl;
    else
	    std::cout << "double: " << this->value << std::endl;
}

Conversion::Conversion( const Conversion& other )
{
    *this = other;
}

Conversion& Conversion::operator =( const Conversion& other )
{
    (void)&other;
    return *this;
}

