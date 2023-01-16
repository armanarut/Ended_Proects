#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
    std::string _target;

public:
    PresidentialPardonForm( const std::string target );
    PresidentialPardonForm& operator =( const PresidentialPardonForm& other );
    PresidentialPardonForm ( const PresidentialPardonForm& other );
    ~PresidentialPardonForm ( void );

    virtual void action( void ) const;
};

#endif