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
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    // Function template to add range
    template <typename Iterator>
    void addRange( Iterator beginIt, Iterator endIt );

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

template <typename Iterator>
void Span::addRange( Iterator beginIt, Iterator endIt )
{
    std::ptrdiff_t rangeSize{ std::distance( beginIt, endIt ) };
    std::ptrdiff_t remainingCapacity = static_cast<std::ptrdiff_t>( m_elements.capacity() ) - m_elements.size();

    if ( rangeSize > remainingCapacity )
        throw NoMoreCapacity( "Cannot add the requested range of size " + std::to_string( rangeSize ) +
                              " since it exceeds the object's remaining capacity of " +
                              std::to_string( remainingCapacity ) );

    for ( auto it{ beginIt }; it != endIt; ++it )
        m_elements.push_back( *it );
}

#endif /* SPAN_H */
