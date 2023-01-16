#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ):
    namePlayer("Default"),
    hitPoints(10),
    energyPoint(10),
    attackDamage(0)
{
    hitPoints_init = this->hitPoints;
    std::cout << "ClapTrap " << namePlayer << " created!" << std::endl;
}

ClapTrap::ClapTrap( const std::string name ):
    namePlayer(name),
    hitPoints(10),
    energyPoint(10),
    attackDamage(0)
{
    hitPoints_init = this->hitPoints;
    std::cout << "ClapTrap " << namePlayer << " created!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
    std::cout << "Copy constructor called!" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator =( const ClapTrap& other )
{
    std::cout << "Copy operator called!" << std::endl;
    namePlayer = other.namePlayer;
    hitPoints = other.hitPoints;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap " << namePlayer << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoint && hitPoints)
    {
        energyPoint--;
        std::cout << "ClapTrap " << namePlayer << " attacks " << target \
            << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << namePlayer << " have no energy or hit points to attack!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (energyPoint && hitPoints)
    {
        if  (hitPoints < amount)
            hitPoints = 0;
        else
            hitPoints -= amount;
        std::cout << "ClapTrap " << namePlayer << " taked " << amount << " damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << namePlayer << " have no energy or hit points to take damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoint && hitPoints)
    {
        energyPoint--;
        if ( hitPoints + amount > hitPoints_init)
            hitPoints = hitPoints_init;
        else
            hitPoints += amount;
        std::cout << "ClapTrap " << namePlayer << " repaired " << amount << " points of hits!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << namePlayer << " have no energy or hit points to be repaired!" << std::endl;

}

std::string ClapTrap::getName( void ) const
{
    return namePlayer;
}

std::ostream &operator << ( std::ostream &ostream, const ClapTrap& other )
{
    ostream << "ClapTrap " << other.getName();
    return ostream;
}