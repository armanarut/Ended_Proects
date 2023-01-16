#pragma once
#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

#include <exception>

class GradeTooHighException: public std::exception
{
    const char * what(void) const throw() {
        return ("The grade is too high!");
    }
};

class GradeTooLowException: public std::exception
{
    const char * what(void) const throw() {
        return ("The grade is too low!");
    }
};

class FormNotSigned: public std::exception
{
    const char * what(void) const throw() {
        return ("The Form is not signed!");
    }
};

class FileDontOpen: public std::exception
{
    const char * what(void) const throw() {
        return ("Can't open file!");
    }
};

class UnknownName: public std::exception
{
    const char * what(void) const throw() {
        return ("The name is not valid!");
    }
};

#endif