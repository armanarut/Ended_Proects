#include "Zombie.hpp"
Zombie* zombieHorde( int N, std::string name );

int main()
{
    Zombie *zombies;
    int     count;

    count = 10;
    zombies = zombieHorde(count, "Foo");
    for (int i = 0; i < count; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}




