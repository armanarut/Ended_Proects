#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal ( void );
    Animal ( const std::string type );
    Animal ( const Animal& other );
    ~Animal ( void );

    Animal& operator =( const Animal& other );

    virtual void makeSound( void ) const;

    std::string getType( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const Animal& other );

#endif