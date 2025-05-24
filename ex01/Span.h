#ifndef SPAN_H
#define SPAN_H

#include <exception>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

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
    unsigned int shortestSpan();
    unsigned int longestSpan();

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
