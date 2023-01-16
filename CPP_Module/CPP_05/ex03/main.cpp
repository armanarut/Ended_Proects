#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 1" << std::endl;
		Bureaucrat bure("Jack", 1);
		Intern newIntern;
		Form *newForm;
		newForm = newIntern.makeForm("unknown name", "Unknown");
		bure.signForm(*newForm);
		bure.executeForm(*newForm);
		delete newForm;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 2" << std::endl;
		Bureaucrat bure("Jack", 1);
		Intern newIntern;
		Form *newForm;
		newForm = newIntern.makeForm("shrubbery creation", "Shrubbery");
		bure.signForm(*newForm);
		bure.executeForm(*newForm);
		delete newForm;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 3" << std::endl;
		Bureaucrat bure("Jack", 1);
		Intern newIntern;
		Form *newForm;
		newForm = newIntern.makeForm("robotomy request", "Robotomy");
		bure.signForm(*newForm);
		bure.executeForm(*newForm);
		delete newForm;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 4" << std::endl;
		Bureaucrat bure("Jack", 1);
		Intern newIntern;
		Form *newForm;
		newForm = newIntern.makeForm("presidential pardon", "Presidential");
		bure.signForm(*newForm);
		bure.executeForm(*newForm);
		delete newForm;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}
