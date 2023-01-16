#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string namePlayer;

public:
    DiamondTrap ( void );
    DiamondTrap ( const std::string name );
    DiamondTrap ( const DiamondTrap& other );
    ~DiamondTrap ( void );

    DiamondTrap& operator =( const DiamondTrap& other );

    void attack(const std::string& target);

    void whoAmI( void );
};


#endif