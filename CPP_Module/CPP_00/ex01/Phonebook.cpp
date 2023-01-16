#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
    this->amount = 0;
    std::cout << "***PhoneBook***" << std::endl;
    std::cout << "Enter command [ADD, SEARCH, EXIT]" << std::endl;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::method_add(void)
{
    static int id;

    if (this->contact[id].new_contact())
    {
        std::cout << "**Contact added N-" << ++id << std::endl;
        if (this->amount < 8)
            this->amount++;
    }
    else
        std::cout << "**Empty contact" << std::endl;
    if (id == 8)
        id = 0;
}

void PhoneBook::method_search(void)
{
    int index;

    if (this->amount == 0)
        std::cout << "**No contact added\n";
    else
    {
        std::cout << "**Enter index [1-" << this->amount << "]\n";
    
        std::cout << "|" << std::setfill('-') << std::setw(44) << "|" << std::endl;
        std::cout << "|     index|first name| last name|  nickname|\n";
        std::cout << "|" << std::setw(44) << "|" << std::endl << std::setfill(' ');
        for (int i = 1; i <= this->amount; i++)
            this->contact[i - 1].displaylist(i);
        std::cout << "|" << std::setfill('-') << std::setw(44) << "|" << std::endl;
        while (!(std::cout << "> ") || !(std::cin >> index)
            || (index <= 0 || index > this->amount))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "**Invalid index" << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        this->contact[index - 1].display(index);
    }
}
