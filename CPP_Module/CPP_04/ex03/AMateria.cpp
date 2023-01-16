#include "AMateria.hpp"

AMateria::AMateria( void ):type()
{
    // std::cout << "AMateria: Default created!" << std::endl;
}

AMateria::AMateria ( const std::string& type ):type(type)
{
    // std::cout << "AMateria: " << type << " created!" << std::endl;
}
AMateria::AMateria( const AMateria& other )
{
    // std::cout << "AMateria: Copy constructor called!" << std::endl;
    *this = other;
}

AMateria& AMateria::operator =( const AMateria& other )
{
    // std::cout << "AMateria: Copy operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

AMateria::~AMateria( void )
{
    // std::cout << "AMateria destroyed!" << std::endl;
}

const std::string& AMateria::getType( void ) const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* There are no materia to use in" << target.getName() << " *" << std::endl;
}

std::ostream &operator << ( std::ostream &ostream, const AMateria& other )
{
    ostream << other.getType();
    return ostream;
}