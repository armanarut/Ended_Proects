#include "Phonebook.hpp"

bool    isdigit_string(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            std::cout << "**Enter only digit" << std::endl;
            return false;
        }
    }
    return true;
}

std::string    make_string10(std::string str)
{
    std::string temp = str;

    if (temp.length() > 10){
        temp.resize(9);
        temp.push_back('.');
    }
    return (temp);
}

int main(void)
{
    PhoneBook book;
    std::string command;
    bool run;

    run = true;
    while(run)
    {
        std::cout << "PhoneBook_v1.3 > ";
        std::getline(std::cin, command);
        if (command == "ADD")
            book.method_add();
        if (command == "SEARCH")
            book.method_search();
        if (command == "EXIT"){
            std::cout << "**closing PhoneBook\n";
            run = false;
        }
    }
    return (0);
}