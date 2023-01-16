#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter
{
private:
    std::string name;
    const static int materias_count = 4;
    AMateria *materias[Character::materias_count];
    AMateria *materias_floor[10];
    int materias_unequiped;

public:
    Character( void );
    Character( std::string name );
    Character ( const Character& other );
    ~Character( void );

    Character& operator =( const Character& other );

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

std::ostream &operator << ( std::ostream &ostream, const ICharacter& other );

#endif