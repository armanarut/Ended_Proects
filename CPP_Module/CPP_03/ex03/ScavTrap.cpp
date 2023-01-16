#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
    this->namePlayer = "Default";
    this->hitPoints = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    this->hitPoints_init = this->hitPoints;
    std::cout << "ScavTrap " << namePlayer << " created!" << std::endl;
}

ScavTrap::ScavTrap( const std::string name )
{
    this->namePlayer = name;
    this->hitPoints = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    this->hitPoints_init = this->hitPoints;
    std::cout << "ScavTrap " << namePlayer << " created!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other ): ClapTrap(other)
{
    std::cout << "Copy constructor called!" << std::endl;
    namePlayer = other.namePlayer;
    hitPoints = other.hitPoints;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
    hitPoints_init = other.hitPoints_init;
}

ScavTrap& ScavTrap::operator =( const ScavTrap& other )
{
    std::cout << "Copy operator called!" << std::endl;
    namePlayer = other.namePlayer;
    hitPoints = other.hitPoints;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
    return *this;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap " << this->namePlayer << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoint && hitPoints)
    {
        energyPoint--;
        std::cout << "ScavTrap " << this->namePlayer << " attacks " << target \
            << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->namePlayer << " have no energy or hit points to attack!" << std::endl;

}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << this->namePlayer << " is now in Gate keeper mode!" << std::endl;
}