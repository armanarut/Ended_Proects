#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
    ClapTrap::namePlayer = std::string("Default").append("_clap_name");
    this->namePlayer = "Default";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoint = ScavTrap::attackDamage;
    this->attackDamage = FragTrap::attackDamage;
    this->hitPoints_init = this->hitPoints;
    std::cout << "DiamondTrap " << namePlayer << " created!" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string name )
{
    ClapTrap::namePlayer = name + "_clap_name";
    this->namePlayer = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoint = ScavTrap::energyPoint;
    this->attackDamage = FragTrap::attackDamage;
    this->hitPoints_init = this->hitPoints;
    std::cout << "DiamondTrap " << namePlayer << " created!" << std::endl;
}


DiamondTrap::DiamondTrap( const DiamondTrap& other ): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "Copy constructor called!" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator =( const DiamondTrap& other )
{
    std::cout << "Copy operator called!" << std::endl;
    namePlayer = other.namePlayer;
    hitPoints = other.hitPoints;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
    return *this;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "DiamondTrap " << namePlayer << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "DiamondTrap my name is " << namePlayer << " and ClapTrap name is " << ClapTrap::namePlayer << "!" << std::endl;
}