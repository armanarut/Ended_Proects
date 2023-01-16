#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
    std::string _target;

public:
    RobotomyRequestForm( const std::string target );
    RobotomyRequestForm& operator =( const RobotomyRequestForm& other );
    RobotomyRequestForm ( const RobotomyRequestForm& other );
    ~RobotomyRequestForm ( void );

    virtual void action( void ) const;
};

#endif