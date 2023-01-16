#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
    std::string type;

public:
    virtual ~AAnimal ( void );

    AAnimal& operator =( const AAnimal& other );

    virtual void makeSound( void ) const = 0;

    std::string getType( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const AAnimal& other );

#endif