#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    {
    std::cout << "---- TEST #1 -----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    {
    std::cout << "---- TEST #1(list) -----" << std::endl;
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        //[...]
        lst.push_back(0);
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
    }
    {
    std::cout << "---- TEST #2 -----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(10);
        mstack.push(6);
        std::cout << "top=" <<  mstack.top() << std::endl;
        mstack.pop();
        std::cout << "pop" << std::endl;
        std::cout << "top=" <<  mstack.top() << std::endl;
        //[...]
        std::cout << "size=" << mstack.size() << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        while (it != mstack.end())
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "copy stack" << std::endl;
        std::stack<int> s(mstack);
        std::cout << "top=" << s.top() << std::endl;
        std::cout << "size=" << s.size() << std::endl;
    }
    return 0;
}