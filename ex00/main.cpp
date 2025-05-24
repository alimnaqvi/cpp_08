#include "easyfind.h"
#include <array>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main()
{
    int         toFind{};
    std::string containerName{};

    // std::vector
    toFind = 11;
    containerName.assign( "std::vector primes" );
    std::vector<int> primes{ 2, 3, 5, 7, 11, 13, 17 };

    std::cout << "Finding " << toFind << " in " << containerName << ":\n";
    printContainer( primes );

    auto foundInVector{ easyfind( primes, toFind ) };

    printFound( primes, toFind, foundInVector, containerName );

    std::cout << "----------------------------------" << '\n';

    // const std::array
    toFind = 42;
    containerName.assign( "std::array fortyTwo" );
    const std::array<int, 5> fortyTwo{ 42, 42, 42, 42, 42 };

    std::cout << "Finding " << toFind << " in " << containerName << ":\n";
    printContainer( fortyTwo );

    auto foundInArray{ easyfind( fortyTwo, toFind ) };

    printFound( fortyTwo, toFind, foundInArray, containerName );

    std::cout << "----------------------------------" << '\n';

    // std::list
    toFind = 89;
    containerName.assign( "std::list fibonacci" );
    std::list fibonacci{ 0, 1 };

    while ( fibonacci.back() < 1000)
        fibonacci.push_back(*(std::prev(fibonacci.end(), 1)) + *(std::prev(fibonacci.end(), 2)));

    std::cout << "Finding " << toFind << " in " << containerName << ":\n";
    printContainer( fibonacci );

    auto foundInList{ easyfind( fibonacci, toFind ) };

    printFound( fibonacci, toFind, foundInList, containerName );

    return 0;
}
