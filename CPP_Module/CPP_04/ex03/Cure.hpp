#pragma once
#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
public:
    Cure ( void );
    Cure ( const std::string& type );
    Cure ( const Cure& other );
    ~Cure ( void );

    Cure& operator =( const Cure& other );

    AMateria* clone() const;
    virtual void use(ICharacter& target);
};

std::ostream &operator << ( std::ostream &ostream, const Cure& other );

#endif