#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ):
    Form(target, 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm " << getName() << " created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm& other ):
    Form(other), _target(other._target)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =( const ShrubberyCreationForm& other )
{
    _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

void ShrubberyCreationForm::action( void ) const
{
    std::ofstream outfile(std::string(_target + "_shrubbery").c_str(),std::ios::trunc);

    if (!outfile.is_open())
        throw FileNotOpen;
    outfile << "                   ,@@@@@@@," << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |" << std::endl;
    outfile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    outfile.close();
    std::cout << "The file " << std::string(_target + "_shrubbery").c_str() << " created!" << std::endl;
}