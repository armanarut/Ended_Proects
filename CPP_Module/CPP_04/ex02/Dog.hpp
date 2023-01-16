#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
private:
    Brain* attribute;

public:
    Dog ( void );
    Dog ( const Dog& other );
    ~Dog ( void );

    Dog& operator =( const Dog& other );

    void makeSound( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const Dog& other );

#endif