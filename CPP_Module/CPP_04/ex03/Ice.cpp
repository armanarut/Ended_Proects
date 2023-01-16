#include "Ice.hpp"

Ice::Ice( void ): AMateria("ice")
{
    // std::cout << "Ice: Default created!" << std::endl;
}

Ice::Ice( const Ice& other ): AMateria(other)
{
    // std::cout << "Ice: Copy constructor called!" << std::endl;
    *this = other;
}

Ice& Ice::operator =( const Ice& other )
{
    // std::cout << "Ice: Copy operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

Ice::~Ice( void )
{
    // std::cout << "Ice destroyed!" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::ostream &operator << ( std::ostream &ostream, const Ice& other )
{
    ostream << other.getType();
    return ostream;
}