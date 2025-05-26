#include "MutantStack.h"
#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

void replaceWithBowl( std::string& str )
{
    auto pos{ str.find( "plate" ) };
    if ( pos != std::string::npos )
        str.replace( pos, 5, "bowl" );
}

int main()
{
    // Simple stack of numbers
    MutantStack<int> naturalNums;

    // It starts empty
    std::cout << "Is naturalNums stack empty: " << std::boolalpha << naturalNums.empty() << '\n';

    // Add numbers 1-10 to the stack
    for ( int i{ 1 }; i <= 10; ++i )
        naturalNums.push( i );

    // We can use range-based loops with MutantStack, unlike std::stack, because of iterators
    std::cout << "naturalNums: ";
    printContainer( naturalNums ); // Uses range-based loop

    // The last number added (10) is always on the top of the stack
    std::cout << "Top of naturalNums stack: " << naturalNums.top() << '\n';

    naturalNums.pop();

    // Removed last element so 9 should be on top now
    std::cout << "Top of naturalNums stack after popping: " << naturalNums.top() << '\n';

    // Another stack initialized with negative numbers (without using push())
    MutantStack<int> negativeNums{ std::deque{ -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 } };

    std::cout << "negativeNums: ";
    printContainer( negativeNums );

    // MutantStack has all member functions of std::stack, such as swap()
    std::cout << "Swapping contents of naturalNums and negativeNums using swap() member function of std::stack:"
              << '\n';
    naturalNums.swap( negativeNums );

    std::cout << "naturalNums after swapping: ";
    printContainer( naturalNums );
    std::cout << "negativeNums after swapping: ";
    printContainer( negativeNums );

    std::cout << "-------------------------------------" << '\n';

    // MutantStack, like std::stack, always has an underlying container type (default std::deque) which can be specified
    MutantStack<std::string, std::list<std::string>> plates;

    plates.push( "Big plate," );
    plates.push( "Medium plate," );
    plates.push( "Small plate" );

    std::cout << "plates: ";
    printContainer( plates );

    std::cout << "Top of plates stack: " << plates.top() << '\n';
    std::cout << "Number of plates: " << plates.size() << '\n';

    // We can use any algorithms that require iterators
    std::for_each( plates.begin(), plates.end(), replaceWithBowl );

    std::cout << "plates after using for_each with replaceWithBowl: ";
    printContainer( plates );

    std::cout << "-------------------------------------" << '\n';

    // A stack can be initialized with a container that is same type as the stack's underlying type
    const std::vector<double> vec{ 3.14, 9.8, 7, 2.7182818284, 0.000001 };

    // A const stack can be initialized with any value but cannot be altered later
    const MutantStack<double, const std::vector<double>> constants{ vec };

    // Attempting to push or pop will result in a compile error due to const-ness
    // constants.push(5.97);

    std::cout << "constants: ";
    printContainer( constants );

    std::cout << "-------------------------------------" << '\n';

    // All constructors and overloaded operators are inherited from the underlying container

    // Copy constructor
    const MutantStack bowls{ plates }; // Let CTAD deduce the types (<std::string, std::list<std::string>>)

    std::cout << "bowls: ";
    printContainer( bowls );

    // Copy assignment operator also works as expected
    MutantStack<std::string, std::list<std::string>> bowlsCopy;
    bowlsCopy = bowls;

    std::cout << "bowlsCopy: ";
    printContainer( bowlsCopy );

    return 0;
}

// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push( 5 );
//     mstack.push( 17 );

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;

//     mstack.push( 3 );
//     mstack.push( 5 );
//     mstack.push( 737 );
//     //[...]
//     mstack.push( 0 );

//     MutantStack<int>::iterator it  = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;
//     while ( it != ite )
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s( mstack );
//     return 0;
// }
