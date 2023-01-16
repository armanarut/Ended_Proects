#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
    this->namePlayer = "Default";
    this->hitPoints = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    this->hitPoints_init = this->hitPoints;
    std::cout << "FragTrap " << this->namePlayer << " created!" << std::endl;
}

FragTrap::FragTrap( const std::string name )
{
    this->namePlayer = name;
    this->hitPoints = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    this->hitPoints_init = this->hitPoints;
    std::cout << "FragTrap " << this->namePlayer << " created!" << std::endl;
}

FragTrap::FragTrap( const FragTrap& other ): ClapTrap(other)
{
    std::cout << "Copy constructor called!" << std::endl;
    namePlayer = other.namePlayer;
    hitPoints = other.hitPoints;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
    hitPoints_init = other.hitPoints_init;
}

FragTrap& FragTrap::operator =( const FragTrap& other )
{
    std::cout << "Copy operator called!" << std::endl;
    namePlayer = other.namePlayer;
    hitPoints = other.hitPoints;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
    return *this;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap " << this->namePlayer << " destroyed!" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << this->namePlayer << " its a positive high fives request." << std::endl;
}