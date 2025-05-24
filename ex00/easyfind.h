#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

/* Look for @toFind in @container and return a const iterator pointing to it if found, else return end() */
template <typename T>
typename T::const_iterator easyfind( T& container, const int toFind )
{
    return std::find( container.cbegin(), container.cend(), toFind );
}

/* Helper function template to print all elements of a container */
template <typename T>
void printContainer( T& container )
{
    std::cout << "{ ";
    for ( const auto& elem : container )
        std::cout << elem << ' ';
    std::cout << "}\n";
}

/* Helper function template to print found message */
template <typename T>
void printFound( T& container, const int toFind, typename T::const_iterator& found, std::string_view containerName )
{
    if ( found != container.cend() )
        std::cout << "Found " << *found << " at index " << std::distance( container.cbegin(), found ) << ".\n";
    else
        std::cout << toFind << " could not be found in " << containerName << ".\n";
}

#endif /* EASYFIND_H */
