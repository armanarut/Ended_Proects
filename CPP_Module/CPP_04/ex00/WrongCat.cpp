#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
    this->type = "WrongCat";
    std::cout << "WrongCat: " << type << " created!" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ):WrongAnimal(other)
{
    std::cout << "WrongCat: Copy constructor called!" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator =( const WrongCat& other )
{
    std::cout << "WrongCat: Copy operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat " << type << " destroyed!" << std::endl;
}

void WrongCat::makeSound( void ) const
{
    std::cout << "meowwwwwww!!" << std::endl;
}

std::ostream &operator << ( std::ostream &ostream, const WrongCat& other )
{
    ostream << "WrongCat " << other.getType();
    return ostream;
}