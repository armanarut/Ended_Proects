#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
#include "MyException.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

    GradeTooHighException HighGrade;
    GradeTooLowException LowGrade;

    void ckeckGrade(int grade) const;

public:
    Bureaucrat ( void );
    Bureaucrat ( const std::string name );
    Bureaucrat ( const std::string name, int grade );
    Bureaucrat ( const Bureaucrat& other );
    Bureaucrat& operator =( const Bureaucrat& other );
    ~Bureaucrat ( void );

    void incrementGrade( void );
    void decrementGrade( void );
    void signForm( Form& form );
    void executeForm(Form const & form);

    std::string getName( void ) const;
    int getGrade( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const Bureaucrat& other );

#endif