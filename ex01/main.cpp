#include "Span.h"
#include <array>
#include <iostream>

void printSpanInfo( const Span& sp )
{
    std::cout << "Span object with size " << sp.size() << " and capacity " << sp.capacity() << ":\n";
    if ( sp.size() < 150 )
        sp.printElements();
    else
    {
        std::cout << "Showing first 100 elements: ";
        sp.printIndexRange( 0, 99 );
    }
    std::cout << "Shortest span: " << sp.shortestSpan() << ", Longest span: " << sp.longestSpan() << "\n\n";
}

int main()
{
    // Simple tests with 7 numbers
    std::cout << "Simple tests with 7 numbers:" << '\n';
    try
    {
        // Shortest span is 5 and longest span is 75
        std::vector vec{ -20, 50, -25, 0, 10, 20, -10 };

        // Capacity 10 (enough to add all 7)
        Span a{ 10 };

        // Add all using addNumber
        for ( const auto& elem : vec )
            a.addNumber( elem );

        std::cout << "Added using addNumber:" << '\n';
        printSpanInfo( a );

        // Capacity 7 (enough to add all 7)
        Span b{ 10 };

        // Add all using addRange
        b.addRange( vec.begin(), vec.end() );

        std::cout << "Added using addRange:" << '\n';
        printSpanInfo( b );

        // Capacity 5 (too small to add all)
        Span c{ 5 };
        for ( const auto& elem : vec )
        {
            std::cout << "Span c has capacity " << c.capacity() << " and size " << c.size()
                      << " before attempting to add " << elem << " to it." << '\n';
            c.addNumber( elem );
        }

        std::cout << "This won't be reached since above will throw an exception" << '\n';
    }
    catch ( const std::exception& e )
    {
        std::cout << "An exception occurred: " << e.what() << '\n';
    }
    std::cout << "-------------------------" << '\n';

    // Default initialization (implicitly 0 capacity)
    std::cout << "Default initialization (implicitly 0 capacity):" << '\n';
    try
    {
        Span a;

        // Can't add anything to it since it has capacity 0
        a.addNumber( 42 );

        std::cout << "This won't be reached since the above will throw an exception" << '\n';
    }
    catch ( const std::exception& e )
    {
        std::cout << "An exception occurred: " << e.what() << '\n';
    }
    std::cout << "-------------------------" << '\n';

    // Initialize with 0 capacity
    std::cout << "Initialize with 0 capacity:" << '\n';
    try
    {
        Span a{ 0 };

        // Can't determine span since it has capacity 0
        printSpanInfo( a );

        std::cout << "This won't be reached since the above will throw an exception" << '\n';
    }
    catch ( const std::exception& e )
    {
        std::cout << "An exception occurred: " << e.what() << '\n';
    }
    std::cout << "-------------------------" << '\n';

    // Capacity of 1
    std::cout << "Capacity of 1:" << '\n';
    try
    {
        Span a{ 1 };

        a.addNumber( 10 );

        // Can't determine span since it has size 1
        printSpanInfo( a );

        std::cout << "This won't be reached since the above will throw an exception" << '\n';
    }
    catch ( const std::exception& e )
    {
        std::cout << "An exception occurred: " << e.what() << '\n';
    }
    std::cout << "-------------------------" << '\n';

    // Only two values (same shortest/longest span and 0 shortest span)
    std::cout << "Only two values (same shortest/longest span and 0 shortest span):" << '\n';
    try
    {
        Span a{ 200 };

        a.addNumber( 80 );
        a.addNumber( 40 );

        // Only two numbers always have the same shortest and longest span
        printSpanInfo( a );

        for ( int i{ 0 }; i < 100; ++i )
            a.addNumber( i % 2 ? 40 : 80 );

        // 102 numbers now but only two values so still the same shortest and longest span
        printSpanInfo( a );
    }
    catch ( const std::exception& e )
    {
        std::cout << "An exception occurred: " << e.what() << '\n';
    }
    std::cout << "-------------------------" << '\n';

    // addRange boundary tests
    
    // 10000 numbers

    // Test with longestSpan being UINT_MAX (because both INT_MAX and INT_MIN are elements)

    // Deep copy tests (copy constructor and assignment operator)

    return 0;
}

// int main()
// {
//     Span sp = Span( 5 );

//     sp.addNumber( 6 );
//     sp.addNumber( 3 );
//     sp.addNumber( 17 );
//     sp.addNumber( 9 );
//     sp.addNumber( 11 );

//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

//     return 0;
// }
