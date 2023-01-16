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
    FormNotSigned NotSigned;

    Form& operator =( const Form& other );

protected:
    void ckeckGrade(int grade) const;

public:
    Form ( void );
    Form( const std::string name, int gradetoSign, int gradetoExcecute );
    Form ( const Form& other );
    virtual ~Form ( void );

    void beSigned( Bureaucrat& bure );
    void execute(Bureaucrat const & executor) const;
    virtual void action( void ) const;
    FileDontOpen FileNotOpen;
    std::string getName( void ) const;
    std::string getSign( void ) const;
};

std::ostream &operator << ( std::ostream &ostream, const Form& other );

#endif