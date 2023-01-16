#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
    std::cout << "WrongAnimal: Default created!" << std::endl;
}

WrongAnimal::WrongAnimal( const std::string type ):
    type(type)
{
    std::cout << "WrongAnimal: " << type << " created!" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
    std::cout << "WrongAnimal: Copy constructor called!" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator =( const WrongAnimal& other )
{
    std::cout << "WrongAnimal: Copy operator called!" << std::endl;
    type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal " << type << " destroyed!" << std::endl;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "random WrongAnimal's sound...!" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
    return type;
}

std::ostream &operator << ( std::ostream &ostream, const WrongAnimal& other )
{
    ostream << "WrongAnimal " << other.getType();
    return ostream;
}