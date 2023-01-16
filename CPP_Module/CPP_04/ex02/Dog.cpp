#include "Dog.hpp"

Dog::Dog( void ):attribute(new Brain())
{
    this->type = "Dog";
    std::cout << "Dog: " << type << " created!" << std::endl;
}

Dog::Dog( const Dog& other )
{
    std::cout << "Dog: Copy constructor called!" << std::endl;
    *this = other;
}

Dog& Dog::operator =( const Dog& other )
{
    std::cout << "Dog: Copy operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

Dog::~Dog( void )
{
    delete attribute;
    std::cout << "Dog " << type << " destroyed!" << std::endl;
}

void Dog::makeSound( void ) const
{
    std::cout << "barkkk!!" << std::endl;
}

std::ostream &operator << ( std::ostream &ostream, const Dog& other )
{
    ostream << "Dog " << other.getType();
    return ostream;
}