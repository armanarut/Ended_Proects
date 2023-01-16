#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string namePlayer;
    unsigned int hitPoints;
    unsigned int energyPoint;
    unsigned int attackDamage;
    unsigned int hitPoints_init;

public:
    ClapTrap ( void );
    ClapTrap ( const std::string name );
    ClapTrap ( const ClapTrap& other );
    virtual ~ClapTrap ( void );

    ClapTrap& operator =( const ClapTrap& other );

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const ClapTrap& other );

#endif