#include <iostream>
#include "Base.hpp"

Base * generate(void)
{
	srand(time(0));
	static unsigned int r = rand();
	switch (r++ % 3)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		return NULL;
	}
}

void identify(Base* p)
{
	if (p == NULL)
		return ;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e){}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (const std::exception& e){}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception& e){}
}

int main( void )
{
	Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

    std::cout << std::endl << "     **Test**" << std::endl;

    std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a );
	std::cout << std::endl;

    std::cout << "b* = "; identify( b );
    std::cout << "b& = "; identify( *b );
	std::cout << std::endl;

    std::cout << "c* = "; identify( c );
    std::cout << "c& = "; identify( *c );
	std::cout << std::endl;

    std::cout << "d* = "; identify( d );
    std::cout << "d& = "; identify( *d );
	std::cout << std::endl;

    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}
