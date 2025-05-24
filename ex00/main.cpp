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

    auto foundVector{ easyfind( primes, toFind ) };

    printFound( primes, toFind, foundVector, containerName );
    // foundVector = std::find( primes.begin(), primes.end(), toFind );

    std::cout << "----------------------------------" << '\n';

    // const std::array
    toFind = 42;
    containerName.assign( "std::array fortyTwo" );
    const std::array<int, 5> fortyTwo{ 42, 42, 42, 42, 42 };

    std::cout << "Finding " << toFind << " in " << containerName << ":\n";
    printContainer( fortyTwo );

    auto foundArray{ easyfind( fortyTwo, toFind ) };

    printFound( fortyTwo, toFind, foundArray, containerName );
    // foundArray = std::find( fortyTwo.begin(), fortyTwo.end(), toFind );

    std::cout << "----------------------------------" << '\n';

    // std::list

    return 0;
}
