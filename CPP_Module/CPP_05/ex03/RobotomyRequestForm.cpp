#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( const std::string target ):
    Form(target, 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm " << getName() << " created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm& other ):
    Form(other), _target(other._target)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator =( const RobotomyRequestForm& other )
{
    _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

void RobotomyRequestForm::action( void ) const
{
    std::cout << "Drrrrrrrrrrrrr~~~~~~~~" << std::endl;
    if (rand() % 2)
        std::cout << "The " << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The " << _target << " failed the robotomy!" << std::endl;
}