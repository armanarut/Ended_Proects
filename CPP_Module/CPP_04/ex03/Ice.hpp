#pragma once
#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
public:
    Ice ( void );
    Ice ( const std::string& type );
    Ice ( const Ice& other );
    ~Ice ( void );

    Ice& operator =( const Ice& other );

    AMateria* clone() const;
    virtual void use(ICharacter& target);
};

std::ostream &operator << ( std::ostream &ostream, const Ice& other );

#endif