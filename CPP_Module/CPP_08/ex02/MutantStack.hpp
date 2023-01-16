#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack( void ) {}
	MutantStack( const MutantStack& other ) {
		*this = other;
	}
	MutantStack& operator=( const MutantStack& other ) {
		if (this == &other)
			return *this;
		this->std::stack<T>::operator =(other);
		return *this;
	}
	~MutantStack( void ) {}

	iterator begin( void ) { return std::stack<T>::c.begin(); }
	iterator end( void ) { return std::stack<T>::c.end(); }
};

#endif