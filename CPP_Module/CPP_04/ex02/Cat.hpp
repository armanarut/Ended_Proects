#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
private:
    Brain* attribute;

public:
    Cat ( void );
    Cat ( const Cat& other );
    ~Cat ( void );

    Cat& operator =( const Cat& other );

    void makeSound( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const Cat& other );

#endif