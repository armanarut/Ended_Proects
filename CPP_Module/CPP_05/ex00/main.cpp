#include "Bureaucrat.hpp"

int main( void ) {

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 1" << std::endl;
		Bureaucrat a("A", 151);
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 2" << std::endl;
		Bureaucrat a("A", -1);
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 3" << std::endl;
		Bureaucrat a("A", 135);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << "incrementGrade: The Grade is " << a.getGrade() << std::endl;
		a.decrementGrade();
		std::cout << "decrementGrade: The Grade is " << a.getGrade() << std::endl;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 4" << std::endl;
		Bureaucrat a("A", 1);
		a.incrementGrade();
		std::cout << "The Grade is " << a.getGrade() << std::endl;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << "   Bureaucrat Test 5" << std::endl;
		Bureaucrat a("A", 150);
		a.decrementGrade();
		std::cout << "The Grade is " << a.getGrade() << std::endl;
		std::cout << "done!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}
