#include "Karen.hpp"

Karen::Karen( void )
{
}

Karen::~Karen( void )
{
}

void    Karen::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
    std::cout << std::endl;
}

void    Karen::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void    Karen::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void    Karen::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void    Karen::complain( std::string level )
{
    void  (Karen::*func[])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4 && levels[i].compare(level))
        i++;
    switch (i){
        case 0:
            (this->*func[0])();
        case 1:
            (this->*func[1])();
        case 2:
            (this->*func[2])();
        case 3:
            (this->*func[3])();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}