#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator   easyfind(T &tab, int value)
{
    typename T::iterator it;
    it = find(tab.begin(), tab.end(), value);
    if (it != tab.end())
        return it;
    throw (std::string("*Not found*"));
}

#endif