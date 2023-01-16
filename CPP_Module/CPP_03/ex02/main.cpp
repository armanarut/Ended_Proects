#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	{
		std::cout << std::endl << "     Class ScavTrap:" << std::endl;
		ScavTrap sc4vtp("Scav Jhon");

		sc4vtp.attack("Jhon Walker");
		sc4vtp.takeDamage(6);
		sc4vtp.beRepaired(4);
		sc4vtp.takeDamage(3);
		sc4vtp.guardGate();
		sc4vtp.beRepaired(8);
		sc4vtp.takeDamage(100);
		sc4vtp.takeDamage(17);
	}
	{
		std::cout << std::endl << "     Class FragTrap:" << std::endl;
		FragTrap sc4vtp("Frag Jhon");

		sc4vtp.attack("Jhon Walker");
		sc4vtp.takeDamage(6);
		sc4vtp.beRepaired(4);
		sc4vtp.takeDamage(3);
		sc4vtp.highFivesGuys();
		sc4vtp.beRepaired(8);
		sc4vtp.takeDamage(100);
		sc4vtp.takeDamage(17);
	}
    return 0;
}
