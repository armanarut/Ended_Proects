#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &club ):_name(name), _club(club)
{
    std::cout << "HumanA: " << this->_name << ", created with weapon: ";
    std::cout << _club.getType() << std::endl;
}

HumanA::~HumanA( void )
{
    std::cout << "HumanA: " << this->_name << " destroyed" << std::endl;
}

void    HumanA::attack( void )
{
    std::cout << this->_name << "  attacks with their " << this->_club.getType() << std::endl;
}

void    HumanA::setWeapon( Weapon club )
{
    this->_club = club;
}