#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "MyException.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool sign;
    const int gradeSign;
    const int gradeExcecute;

    GradeTooHighException HighGrade;
    GradeTooLowException LowGrade;

    Form& operator =( const Form& other );
    void ckeckGrade(int grade) const;

public:
    Form ( void );
    Form( const std::string name, int gradetoSign, int gradetoExcecute );
    Form ( const Form& other );
    ~Form ( void );

    void beSigned( Bureaucrat& bure );

    std::string getName( void ) const;
    std::string getSign( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const Form& other );

#endif