#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
    std::string _name;
    Weapon &_club;

public:
    HumanA( std::string name, Weapon &club );
    ~HumanA( void );

    void    attack( void );
    void    setWeapon( Weapon club );
};

#endif