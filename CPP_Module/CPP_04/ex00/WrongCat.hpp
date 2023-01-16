#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
    WrongCat ( void );
    WrongCat ( const WrongCat& other );
    ~WrongCat ( void );

    WrongCat& operator =( const WrongCat& other );

    void makeSound( void ) const;
    
    // std::string getType( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const WrongCat& other );

#endif