#include "ClapTrap.hpp"

int main( void ) {

	{
		std::cout << std::endl << "     Class ClapTrap:" << std::endl;
		ClapTrap cl4ptp("Clap Jhon");

		cl4ptp.attack("Jhon Walker");
		cl4ptp.takeDamage(6);
		cl4ptp.beRepaired(4);
		cl4ptp.takeDamage(3);
		cl4ptp.beRepaired(8);
		cl4ptp.takeDamage(100);
		cl4ptp.takeDamage(17);
	}
    return 0;
}
