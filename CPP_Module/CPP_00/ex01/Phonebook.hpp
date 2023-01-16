#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contact[8];
    int     amount;
public:
    PhoneBook();
    virtual ~PhoneBook();

    void    method_add(void);
    void    method_search(void);
};

#endif