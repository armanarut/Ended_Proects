#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T				*arr;
	size_t	_size;

public:
	Array( void );
	Array( unsigned int size );
	Array( const Array<T>& other );
	Array<T>& operator=( const Array<T>& other );
	~Array( void );

	T& operator[]( size_t i ) const;

	size_t size( void ) const;
};

template <typename T>
Array<T>::Array( void ):arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array( unsigned int size ):arr(new T[size]), _size(size)
{
}

template <typename T>
Array<T>::Array( const Array<T>& other )
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array<T>& other )
{
	// delete [] arr;
	this->arr = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); ++i)
		this->arr[i] = other.arr[i];
	this->_size = other.size();
	return *this;
}

template <typename T>
Array<T>::~Array( void )
{
	delete [] arr;
}

template <typename T>
T& Array<T>::operator[]( size_t i ) const
{
	if (i < 0 || i >= _size)
		throw (std::invalid_argument("Array index out of range"));
	return arr[i];
}


template <typename T>
size_t Array<T>::size( void ) const
{
	return _size;
}

#endif