#include "Karen.hpp"

int main( int argc, char *argv[])
{
    Karen karen;

    if (argc == 2)
        karen.complain(argv[1]);
    else
        cout << "[ please enter 1 argument ]" << endl;
    return (0);
}