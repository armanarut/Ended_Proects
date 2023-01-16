#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string target ):
    Form(target, 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm " << getName() << " created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm& other ):
    Form(other), _target(other._target)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator =( const PresidentialPardonForm& other )
{
    _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

void PresidentialPardonForm::action( void ) const
{
    std::cout << "The " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}