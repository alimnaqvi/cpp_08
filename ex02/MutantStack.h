#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
  public:
    // inherit all constructors from std::stack
    using std::stack<T, Container>::stack;

    // iterator types (public so, e.g., MutantStack<int>::iterator is available)

    using iterator               = typename Container::iterator;
    using const_iterator         = typename Container::const_iterator;
    using reverse_iterator       = typename Container::reverse_iterator;
    using const_reverse_iterator = typename Container::const_reverse_iterator;

    // Iterator members (@c is the underlying container of any std::stack)

    iterator begin() noexcept
    {
        return this->c.begin();
    }
    const_iterator cbegin() noexcept
    {
        return this->c.cbegin();
    }
    iterator end() noexcept
    {
        return this->c.end();
    }
    const_iterator cend() noexcept
    {
        return this->c.cend();
    }
    reverse_iterator rbegin() noexcept
    {
        return this->c.rbegin();
    }
    const_reverse_iterator crbegin() noexcept
    {
        return this->c.crbegin();
    }
    reverse_iterator rend() noexcept
    {
        return this->c.rend();
    }
    const_reverse_iterator crend() noexcept
    {
        return this->c.crend();
    }

    // const overloads of all of the above iterator members

    const_iterator begin() const noexcept
    {
        return this->c.begin();
    }
    const_iterator cbegin() const noexcept
    {
        return this->c.cbegin();
    }
    const_iterator end() const noexcept
    {
        return this->c.end();
    }
    const_iterator cend() const noexcept
    {
        return this->c.cend();
    }
    const_reverse_iterator rbegin() const noexcept
    {
        return this->c.rbegin();
    }
    const_reverse_iterator crbegin() const noexcept
    {
        return this->c.crbegin();
    }
    const_reverse_iterator rend() const noexcept
    {
        return this->c.rend();
    }
    const_reverse_iterator crend() const noexcept
    {
        return this->c.crend();
    }
};

/* Helper function template to print all elements of a container (must be have iterator members like begin()) */
template <typename T>
void printContainer( T& container )
{
    std::cout << "{ ";
    for ( const auto& elem : container )
        std::cout << elem << ' ';
    std::cout << "}\n";
}

#endif /* MUTANTSTACK_H */
