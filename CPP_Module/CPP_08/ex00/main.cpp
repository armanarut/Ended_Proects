#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <set>

int main(void)
{
    int tab[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
    int num1 = 15;
    int num2 = 42;
    
    std::cout << std::endl << "        **Vector**" << std::endl;
    {
        std::vector<int> vec(tab, tab + sizeof(tab)/sizeof(int));
        std::vector<int>::iterator v_it;
        try {
            v_it = easyfind(vec, num1);
            std::cout << "last:" << *(v_it - 1) << " found:" << *v_it << " next: " << *(v_it + 1) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
        try {
            v_it = easyfind(vec, num2);
            std::cout << "last:" << *(v_it - 1) << " found:" << *v_it << " next: " << *(v_it + 1) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
    }

    std::cout << std::endl << "        **Deque**" << std::endl;
    {
        std::deque<int> dec(tab, tab + sizeof(tab)/sizeof(int));
        std::deque<int>::iterator d_it;
        try {
            d_it = easyfind(dec, num1);
            std::cout << "last:" << *(d_it - 1) << " found:" << *d_it << " next: " << *(d_it + 1) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
        try {
            d_it = easyfind(dec, num2);
            std::cout << "last:" << *(d_it - 1) << " found:" << *d_it << " next: " << *(d_it + 1) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
    }

    std::cout << std::endl << "        **List**" << std::endl;
    {
        std::list<int> lst(tab, tab + sizeof(tab)/sizeof(int));
        std::list<int>::iterator l_it;
        try {
            l_it = easyfind(lst, num1);
            std::cout << "last:" << *(--l_it) << " found:" << *(++l_it) << " next: " << *(++l_it) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
        try {
            l_it = easyfind(lst, num2);
            std::cout << "last:" << *(--l_it) << " found:" << *(++l_it) << " next: " << *(++l_it) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
    }

    std::cout << std::endl << "        **Set**" << std::endl;
    {
        std::set<int> st(tab, tab + sizeof(tab)/sizeof(int));
        std::set<int>::iterator s_it;
        try {
            s_it = easyfind(st, num1);
            std::cout << "last:" << *(--s_it) << " found:" << *(++s_it) << " next: " << *(++s_it) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
        try {
            s_it = easyfind(st, num2);
            std::cout << "last:" << *(--s_it) << " found:" << *(++s_it) << " next: " << *(++s_it) << std::endl;
        }
        catch (const std::string& e) {
            std::cerr << "Error: " << e << std::endl;
        }
    }

    return 0;
}
