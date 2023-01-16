#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria ( void );
    AMateria ( const std::string& type );
    AMateria ( const AMateria& other );
    virtual ~AMateria ( void );

    AMateria& operator =( const AMateria& other );

    const std::string& getType( void ) const;

    virtual AMateria* clone() const = 0;
    virtual void use( ICharacter& target );
};

std::ostream &operator << ( std::ostream &ostream, const AMateria& other );

#endif