#include "Cure.hpp"

Cure::Cure( void ): AMateria("cure")
{
    // std::cout << "Cure: Default created!" << std::endl;
}

Cure::Cure( const Cure& other ): AMateria(other)
{
    // std::cout << "Cure: Copy constructor called!" << std::endl;
    *this = other;
}

Cure& Cure::operator =( const Cure& other )
{
    // std::cout << "Cure: Copy operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

Cure::~Cure( void )
{
    // std::cout << "Cure destroyed!" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

std::ostream &operator << ( std::ostream &ostream, const Cure& other )
{
    ostream << other.getType();
    return ostream;
}