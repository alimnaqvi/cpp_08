#include "Span.h"
#include <iostream>

// int main()
// {
//     // Default initialization (0 capacity)

//     // Test with longestSpan being UINT_MAX (because both INT_MAX and INT_MIN are elements)

//     // Deep copy tests (copy constructor and assignment operator)

//     return 0;
// }

int main()
{
    Span sp = Span( 5 );

    sp.addNumber( 6 );
    sp.addNumber( 3 );
    sp.addNumber( 17 );
    sp.addNumber( 9 );
    sp.addNumber( 11 );

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
