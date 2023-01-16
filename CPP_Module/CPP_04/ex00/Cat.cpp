#include "Cat.hpp"

Cat::Cat( void )
{
    this->type = "Cat";
    std::cout << "Cat: " << type << " created!" << std::endl;
}

Cat::Cat( const Cat& other ):Animal(other)
{
    std::cout << "Cat: Copy constructor called!" << std::endl;
    *this = other;
}

Cat& Cat::operator =( const Cat& other )
{
    std::cout << "Cat: Copy operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

Cat::~Cat( void )
{
    std::cout << "Cat " << type << " destroyed!" << std::endl;
}

void Cat::makeSound( void ) const
{
    std::cout << "meowwwwwww!!" << std::endl;
}

std::ostream &operator << ( std::ostream &ostream, const Cat& other )
{
    ostream << "Cat " << other.getType();
    return ostream;
}