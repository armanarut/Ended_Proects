#include "Form.hpp"

void Form::ckeckGrade(int grade) const
{
    if (grade < 1)
        throw HighGrade;
    else if (grade > 150)
        throw LowGrade;
}

Form::Form( void ):
    _name(),
    sign(),
    gradeSign(),
    gradeExcecute()
{
}

Form::Form( const std::string name, int gradetoSign, int gradetoExcecute ):
    _name(name),
    sign(),
    gradeSign(gradetoSign),
    gradeExcecute(gradetoExcecute)
{
    this->ckeckGrade(gradetoSign);
    this->ckeckGrade(gradetoExcecute);
    std::cout << "Form " << getName() << " created!" << std::endl;
}

Form::Form ( const Form& other ):
    _name(other._name),
    sign(other.sign),
    gradeSign(other.gradeSign),
    gradeExcecute(other.gradeExcecute)
{
    *this = other;
}

Form& Form::operator =( const Form& other )
{
    sign = other.sign;
    return *this;
}

Form::~Form( void )
{
}

void Form::beSigned( Bureaucrat& bure )
{
    if (gradeSign < bure.getGrade())
        throw LowGrade;
    sign = true;
    std::cout << bure.getName() << " signed " << this->getName() << std::endl;
}

std::string Form::getName( void ) const
{
    return _name;
}

std::string Form::getSign( void ) const
{
    if (sign)
        return "signed";
    else
        return "not signed";
}

std::ostream &operator << ( std::ostream &ostream, const Form& other )
{
    ostream << "Form " << other.getName() << " is " << other.getSign() << ".";
    return ostream;
}