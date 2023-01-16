#include "Contact.hpp"
#include "header.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

int    Contact::new_contact()
{
    std::cout << "first_name > ";
    std::getline(std::cin, this->first_name);
    std::cout << "last_name > ";
    std::getline(std::cin, this->last_name);
    std::cout << "nickname > ";
    std::getline(std::cin, this->nickname);
    do {
        std::cout << "phone_number > ";
        std::getline(std::cin, this->phone_number);
    } while (!isdigit_string(phone_number));
    std::cout << "darkest_secret > ";
    std::getline(std::cin, this->darkest_secret);
    if (this->first_name.length() == 0
        && this->last_name.length() == 0
        && this->nickname.length() == 0
        && this->phone_number.length() == 0
        && this->darkest_secret.length() == 0)
        return (false);
    return (true);
}

void    Contact::displaylist(int index)
{
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << make_string10(this->first_name);
    std::cout << "|" << std::setw(10) << make_string10(this->last_name);
    std::cout << "|" << std::setw(10) << make_string10(this->nickname);
    std::cout << "|" << std::endl;
}

void    Contact::display(int index)
{
    std::cout << "**Contact index: " << index << std::endl;
    std::cout << "     first name: " << this->first_name << ";" << std::endl;
    std::cout << "      last name: " << this->last_name << ";" << std::endl;
    std::cout << "       nickname: " << this->nickname << ";" << std::endl;
    std::cout << "   phone number: " << this->phone_number << ";" << std::endl;
    std::cout << " darkest secret: " << this->darkest_secret << ";" << std::endl;
}