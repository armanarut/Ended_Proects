#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void print_char(const T& c)
{
	std::cout << (char)c;
}

template <typename T>
void print_it(const T& p)
{
	std::cout << p << std::endl;
}

template <typename T>
void iter(T *arr, int lenght, void(f)(const T&))
{
	for (int i = 0; i < lenght; i++)
		f(arr[i]);
}
#endif