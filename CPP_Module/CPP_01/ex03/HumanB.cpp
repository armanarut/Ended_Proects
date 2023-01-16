#include "HumanB.hpp"

HumanB::HumanB( std::string name ):_name(name), _club(NULL)
{
    std::cout << "HumanB: " << this->_name << ", created with no weapon" << std::endl;
}

HumanB::~HumanB( void )
{
    std::cout << "HumanB: " << this->_name << " destroyed" << std::endl;
}

void    HumanB::attack( void )
{
    std::cout << this->_name << "  attacks with their ";
    std::cout << this->_club->getType() << std::endl;
}

void    HumanB::setWeapon( Weapon &club )
{
    this->_club = &club;
}