#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 1" << std::endl;
		Bureaucrat bure("Jack", 1);
		ShrubberyCreationForm a("Shrubbery");
		RobotomyRequestForm b("Robotomy");
		PresidentialPardonForm c("Presidential");
		bure.executeForm(a);
		bure.executeForm(b);
		bure.executeForm(c);
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 2" << std::endl;
		Bureaucrat bure("Jack", 140);
		ShrubberyCreationForm a("Shrubbery");
		RobotomyRequestForm b("Robotomy");
		PresidentialPardonForm c("Presidential");
		bure.signForm(a);
		bure.executeForm(a);
		bure.signForm(b);
		bure.executeForm(b);
		bure.signForm(c);
		bure.executeForm(c);
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 3" << std::endl;
		Bureaucrat bure("Jack", 50);
		ShrubberyCreationForm a("Shrubbery");
		RobotomyRequestForm b("Robotomy");
		PresidentialPardonForm c("Presidential");
		bure.signForm(a);
		bure.executeForm(a);
		bure.signForm(b);
		bure.executeForm(b);
		bure.signForm(c);
		bure.executeForm(c);
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 4" << std::endl;
		Bureaucrat bure("Jack", 10);
		ShrubberyCreationForm a("Shrubbery");
		RobotomyRequestForm b("Robotomy");
		PresidentialPardonForm c("Presidential");
		bure.signForm(a);
		bure.executeForm(a);
		bure.signForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.executeForm(b);
		bure.signForm(c);
		bure.executeForm(c);
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << std::endl << "   Bureaucrat Test 5" << std::endl;
		Bureaucrat bure("Jack", 2);
		ShrubberyCreationForm a("Shrubbery");
		RobotomyRequestForm b("Robotomy");
		PresidentialPardonForm c("Presidential");
		bure.signForm(a);
		bure.executeForm(a);
		bure.signForm(b);
		bure.executeForm(b);
		bure.signForm(c);
		bure.executeForm(c);
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}
