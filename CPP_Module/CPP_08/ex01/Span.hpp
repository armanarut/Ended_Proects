#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

typedef std::vector<int>::iterator it;

class Span
{
private:
	std::vector<int>	tab;
	size_t				_size;

public:
	Span( void );
	Span( unsigned int N );
	Span( const Span& other );
	Span& operator=( const Span& other );
	~Span( void );

	void addNumber(int number);
	void addSequence(it begin, it end);
	int shortestSpan( void );
	int longestSpan( void );

	std::pair<it, it> getTab( void ); 
};

std::ostream &operator << ( std::ostream &ostream, Span& other );

#endif