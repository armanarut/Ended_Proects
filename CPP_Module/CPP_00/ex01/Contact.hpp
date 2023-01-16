#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
    std::string  first_name;
    std::string  last_name;
    std::string  nickname;
    std::string  phone_number;
    std::string  darkest_secret;
public:
    Contact();
    virtual ~Contact();

    int    new_contact(void);
    void    displaylist(int index);
    void    display(int index);
};

#endif