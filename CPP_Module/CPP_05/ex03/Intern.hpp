#pragma once
#ifndef Intern_HPP
# define Intern_HPP

#include <iostream>
#include "MyException.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:

public:
    Intern ( void );
    Intern ( const Intern& other );
    Intern& operator =( const Intern& other );
    ~Intern ( void );

    UnknownName UnknownName;

    Form* makeForm(const std::string name, const std::string target );
};

std::ostream &operator << ( std::ostream &ostream, const Intern& other );

#endif