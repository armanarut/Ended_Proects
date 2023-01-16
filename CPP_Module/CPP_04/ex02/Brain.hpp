#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string called[100];

public:
    Brain ( void );
    Brain ( const Brain& other );
    ~Brain ( void );

    Brain& operator =( const Brain& other );
};

#endif