#include "Zombie.hpp"
Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie *zombie;
    
    zombie = newZombie("Foo");
    zombie->announce();
    randomChump("Jack");
    delete(zombie);
    return 0;
}

