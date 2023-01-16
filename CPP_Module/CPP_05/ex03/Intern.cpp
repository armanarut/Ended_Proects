#include "Intern.hpp"

Intern::Intern( void )
{
    std::cout << "Intern created!" << std::endl;
}

Intern::Intern( const Intern& other )
{
    *this = other;
}

Intern& Intern::operator =( const Intern& other )
{
    (void)other;
    return *this;
}

Intern::~Intern( void )
{
}

Form* Intern::makeForm(const std::string name, const std::string target )
{
    const std::string _forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int idx = 0;

    for (; idx < 3; idx++)
        if (_forms[idx] == name)
            break;
    switch (idx) {
    case 0:
        return new ShrubberyCreationForm(target);
    case 1:
        return new RobotomyRequestForm(target);
    case 2:
        return new PresidentialPardonForm(target);
    default:
        throw UnknownName;
    }
    return NULL;
}