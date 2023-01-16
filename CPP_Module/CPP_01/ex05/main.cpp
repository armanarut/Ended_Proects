#include "Karen.hpp"

int main( void)
{
    Karen karen;
    std::string command;
    bool run;

    std::cout << "Enter level" << std::endl << "  for exit enter [EXIT]" << std::endl;
    run = true;
    while(run)
    {
        std::cout << "> ";
        getline(std::cin, command);
        if (command == "EXIT"){
            std::cout << "**bye Karen\n";
            run = false;
        }
        else
            karen.complain(command);
    }
    return (0);
}