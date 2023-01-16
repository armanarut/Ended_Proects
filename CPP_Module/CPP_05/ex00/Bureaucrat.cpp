#include "Bureaucrat.hpp"


void Bureaucrat::ckeckGrade(int grade) const
{
    if (grade < 1)
        throw HighGrade;
    else if (grade > 150)
        throw LowGrade;
}

Bureaucrat::Bureaucrat( void ):
    _name(),
    _grade(150)
{
}

Bureaucrat::Bureaucrat( const std::string name ):
    _name(name),
    _grade(150)
{
}

Bureaucrat::Bureaucrat( const std::string name, int grade ):
    _name(name)
{
    this->ckeckGrade(grade);
    _grade = grade;
    std::cout << "Bureaucrat " << getName() << " created with grade " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
    _grade = other._grade;
    *this = other;
}

Bureaucrat& Bureaucrat::operator =( const Bureaucrat& other )
{
    _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat( void )
{
}

void Bureaucrat::incrementGrade( void )
{
    this->ckeckGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade( void )
{
    this->ckeckGrade(_grade + 1);
    _grade++;
}

std::string Bureaucrat::getName( void ) const
{
    return _name;
}

int Bureaucrat::getGrade( void ) const
{
    return _grade;
}

std::ostream &operator << ( std::ostream &ostream, const Bureaucrat& other )
{
    ostream << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
    return ostream;
}