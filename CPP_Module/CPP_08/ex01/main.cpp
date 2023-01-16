#include "Span.hpp"

int main(void)
{
    std::cout << "---- TEST #1 -----" << std::endl;
    {
        Span sp = Span( 5 );

        sp.addNumber( 6 );
        sp.addNumber( 3 );
        sp.addNumber( 9 );
        sp.addNumber( 17 );
        sp.addNumber( 11 );

        std::cout << "sp: " << sp << std::endl;

        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    }

    std::cout << "\n---- TEST #2 -----" << std::endl;
    {
        try {
            Span sp1 = Span( 5 );

            sp1.addNumber( 6 );
            sp1.addNumber( 3 );
            sp1.addNumber( 9 );
            sp1.addNumber( 17 );
            sp1.addNumber( 11 );
            sp1.addNumber( 16 );

            std::cout << "sp1: " << sp1 << std::endl;

            std::cout << "longestSpan: " << sp1.longestSpan() << std::endl;
            std::cout << "shortestSpan: " << sp1.shortestSpan() << std::endl;
            
        } catch ( std::exception& e ) {
            std::cout << e.what() << std::endl; 
        }
    }

    std::cout << "\n---- TEST #3 -----" << std::endl;
    {
        try {
            std::vector<int>    l( 10000 );
            std::srand( time ( NULL ) );
            std::generate( l.begin(), l.end(), std::rand );

            Span span( l.size() );

            span.addSequence( l.begin(), l.end() );

            std::cout << "Longest span: " << span.longestSpan() << std::endl;
            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            
        } catch ( std::exception& e ) {
            std::cout << e.what() << std::endl; 
        }
    }

    std::cout << "\n---- TEST #4 -----" << std::endl;
    {
        try {
            std::vector<int>    l( 10 );
            std::srand( time ( NULL ) );
            std::generate( l.begin(), l.end(), std::rand );

            Span span( l.size() - 1 );

            span.addSequence( l.begin(), l.end() );

            std::cout << "Longest span: " << span.longestSpan() << std::endl;
            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            
        } catch ( std::exception& e ) {
            std::cout << e.what() << std::endl; 
        }
    }

    return 0;
}
