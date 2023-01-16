#include <iostream>

int main()
{
    std::string s0 ("HI THIS IS BRAIN");
    std::string *s1 = &s0;
    std::string &s2 = s0;

    std::cout << s0 << std::endl;
    std::cout << *s1 << std::endl;
    std::cout << s2 << std::endl;

    std::cout << &s0 << std::endl;
    std::cout << s1 << std::endl;
    std::cout << &s2 << std::endl;

    return (0);
}