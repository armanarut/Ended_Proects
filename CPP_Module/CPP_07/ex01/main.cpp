#include "iter.hpp"

int main() {

int tab[] = { 72, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 33 };
std::string tab2[4] = {"abc", "dfg", "hij", "klm"};


std::cout << std::endl << "   ***Integer***" << std::endl;
iter( tab, sizeof(tab)/sizeof(int), print_it );
iter( tab, sizeof(tab)/sizeof(int), print_char );
std::cout << std::endl;

std::cout << std::endl << "   ***String***" << std::endl;
iter( tab2, sizeof(tab2)/sizeof(std::string), print_it );

return 0;
}

// class Awesome
// {
// public:
// 	Awesome( void ) : _n( 42 ) { return; }
// 	int get( void ) const { return this->_n; }
// private:
// 	int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {

// int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// Awesome tab2[5];

// iter( tab, 5, print );
// iter( tab2, 5, print );

// return 0;
// }