#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal ( void );
    WrongAnimal ( const std::string type );
    WrongAnimal ( const WrongAnimal& other );
    ~WrongAnimal ( void );

    WrongAnimal& operator =( const WrongAnimal& other );

    void makeSound( void ) const;

    std::string getType( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const WrongAnimal& other );

#endif