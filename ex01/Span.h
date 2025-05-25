#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

class Span
{
  public:
    // Orthodox canonical form requirements
    Span();
    Span( const Span& other );
    Span& operator=( const Span& other );
    ~Span();

    // Main parameterized constructor
    Span( unsigned int N );

    // Main member functions
    void         addNumber( int i );
    // ! Possibly make the below too templates T::iterator / T::const_iterator (so should work with std::array too)
    void         addRange( std::vector<int>::iterator beginIt, std::vector<int>::iterator endIt );
    void         addRange( std::vector<int>::const_iterator beginIt, std::vector<int>::const_iterator endIt );
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    // Print elements and get size/capacity
    void        printElements() const;
    void        printIndexRange( std::size_t first, std::size_t last ) const;
    std::size_t size() const;
    std::size_t capacity() const;

    // Exception classes
    class NoMoreCapacity : public std::exception
    {
      public:
        NoMoreCapacity( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };

    class SpanNotApplicable : public std::exception
    {
      public:
        SpanNotApplicable( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };

  private:
    std::vector<int> m_elements;
};

#endif /* SPAN_H */
