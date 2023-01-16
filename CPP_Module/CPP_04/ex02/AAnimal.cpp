#include "AAnimal.hpp"

AAnimal& AAnimal::operator =( const AAnimal& other )
{
    std::cout << "AAnimal: Copy operator called!" << std::endl;
    type = other.type;
    return *this;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal " << type << " destroyed!" << std::endl;
}

std::string AAnimal::getType( void ) const
{
    return type;
}

std::ostream &operator << ( std::ostream &ostream, const AAnimal& other )
{
    ostream << "AAnimal " << other.getType();
    return ostream;
}