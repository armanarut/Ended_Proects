#include "Span.hpp"

Span::Span( void ):_size(0)
{
}

Span::Span( unsigned int N ):_size(N)
{
}

Span::Span( const Span& other )
{
	*this = other;
}

Span& Span::operator=( const Span& other )
{
	this->tab = other.tab;
	this->_size = other._size;
	return *this;
}

Span::~Span( void )
{
}

void Span::addNumber(int number)
{
    if (tab.size() >= _size)
        throw (std::invalid_argument("list is full"));
    tab.push_back(number);
    std::sort(tab.begin(), tab.end());
}

void Span::addSequence(it begin, it end)
{
    it tmp = begin;
    for (size_t num = 0; tmp != end; ++tmp)
        if (++num > _size)
            throw (std::invalid_argument("list is full"));  
    while (begin != end)
        tab.push_back(*begin++);
    std::sort(tab.begin(), tab.end());
}

int Span::shortestSpan( void )
{
    if (tab.size() < 2)
        throw (std::invalid_argument("less then two args"));

    it iter = tab.begin();
    int dif = *(iter + 1) - *iter;
    iter++;
    for (int tmp; iter != tab.end(); iter++) {
        tmp = *iter - *(iter - 1);
        if (tmp < dif)
            dif = tmp;
    }
    return dif;
}

int Span::longestSpan( void )
{
    if (tab.size() < 2)
        throw (std::out_of_range("less then two args"));

    it min = std::min_element(tab.begin(), tab.end());
    it max = std::max_element(tab.begin(), tab.end());
    return *max - *min;
}

std::pair<it, it> Span::getTab( void )
{
    std::pair<it, it> result;

    result.first = tab.begin();
    result.second = tab.end();
    return result;
}

std::ostream &operator << ( std::ostream &ostream, Span& other )
{
    std::pair<it, it> p = other.getTab();
    for (it iter = p.first; iter != p.second; ++iter)
        ostream << *iter << " ";
    ostream << std::endl;
    return ostream;
}