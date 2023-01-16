#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
    std::string _target;

public:
    ShrubberyCreationForm( const std::string target );
    ShrubberyCreationForm& operator =( const ShrubberyCreationForm& other );
    ShrubberyCreationForm ( const ShrubberyCreationForm& other );
    ~ShrubberyCreationForm ( void );

    virtual void action( void ) const;
};

#endif