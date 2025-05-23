#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

/* Look for @toFind in @container and return an iterator pointing to it if found, else return end() */
template <typename T>
typename T::iterator easyfind( T& container, int toFind )
{
    return std::find( container.begin(), container.end(), toFind );
}

/* Helper function template to print all elements of a container */
template <typename T>
void printContainer( T& container )
{
    std::cout << "{ ";
    for ( const auto& elem : container )
    {
        std::cout << elem << ' ';
    }
    std::cout << "}\n";
}

/* Helper function template to print found message */
template <typename T>
void printFound( T& container, int toFind, typename T::iterator& found, std::string_view containerName )
{
    if ( found != container.end() )
        std::cout << "Found " << *found << " at index " << found - container.begin() << ".\n";
    else
        std::cout << toFind << " could not be found in " << containerName << ".\n";
}

#endif /* EASYFIND_H */
