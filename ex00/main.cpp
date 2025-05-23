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
    std::vector primes{ 2, 3, 5, 7, 11, 13, 17 };

    std::cout << "Finding " << toFind << " in " << containerName << ":\n";
    printContainer( primes );

    auto found{ easyfind( primes, toFind ) };

    printFound( primes, toFind, found, containerName );
    // found = std::find( primes.begin(), primes.end(), toFind );

    std::cout << "----------------------------------" << '\n';

    // std::array

    // std::list

    return 0;
}
