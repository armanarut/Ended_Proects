#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie( void )
{
    std::cout << this->name << ": destroyed\n";
}

void Zombie::announce( void ) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
