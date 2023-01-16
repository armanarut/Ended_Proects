#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {

	std::cout << std::endl << "   Animal" << std::endl;
	Animal* meta[20];
	for (int i = 0; i < 10; i++)
		meta[i] = new Dog();
	for (int i = 10; i < 20; i++)
		meta[i] = new Cat();

	for (int i = 0; i < 20; i++)
	{
		std::cout << i+1 << ": " << meta[i]->getType() << " ";
		meta[i]->makeSound();
	}

	for (int i = 0; i < 20; i++)
		delete meta[i];

    return 0;
}
