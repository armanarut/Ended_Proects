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

#endif