#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain: Default created!" << std::endl;
}

Brain::Brain( const Brain& other )
{
    std::cout << "Brain: Copy constructor called!" << std::endl;
    *this = other;
}

Brain& Brain::operator =( const Brain& other )
{
    std::cout << "Brain: Copy operator called!" << std::endl;
    for (int i = 0; i < 100; i++)
        this->called[i] = other.called[i];
    return *this;
}

Brain::~Brain( void )
{
    std::cout << "Brain destroyed!" << std::endl;
}