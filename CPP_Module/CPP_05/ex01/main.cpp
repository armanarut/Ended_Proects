#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 1" << std::endl;
		Bureaucrat bure("Jack", 95);
		Form form("Project", 151, 0);
		std::cout << form << std::endl;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 2" << std::endl;
		Bureaucrat bure("Jack", 95);
		Form form("Project", 0, 1);
		std::cout << form << std::endl;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 3" << std::endl;
		Bureaucrat bure("Jack", 95);
		Form form("Project", 55, 1);
		std::cout << form << std::endl;
		bure.signForm(form);
		std::cout << form << std::endl;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 4" << std::endl;
		Bureaucrat bure("Jack", 30);
		Form form("Project", 55, 1);
		std::cout << form << std::endl;
		bure.signForm(form);
		std::cout << form << std::endl;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}
