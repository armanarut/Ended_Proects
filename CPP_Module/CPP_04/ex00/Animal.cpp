#include "Animal.hpp"

Animal::Animal( void )
{
    std::cout << "Animal: Default created!" << std::endl;
}

Animal::Animal( const std::string type ):
    type(type)
{
    std::cout << "Animal: " << type << " created!" << std::endl;
}

Animal::Animal( const Animal& other )
{
    std::cout << "Animal: Copy constructor called!" << std::endl;
    *this = other;
}

Animal& Animal::operator =( const Animal& other )
{
    std::cout << "Animal: Copy operator called!" << std::endl;
    type = other.type;
    return *this;
}

Animal::~Animal( void )
{
    std::cout << "Animal " << type << " destroyed!" << std::endl;
}

void Animal::makeSound( void ) const
{
    std::cout << "random Animal's sound...!" << std::endl;
}

std::string Animal::getType( void ) const
{
    return type;
}

std::ostream &operator << ( std::ostream &ostream, const Animal& other )
{
    ostream << "Animal " << other.getType();
    return ostream;
}