#include "Span.h"

// Orthodox canonical form requirements

Span::Span()
    : m_elements{}
{
}

Span::Span( const Span& other )
    : m_elements{ other.m_elements }
{
}

Span& Span::operator=( const Span& other )
{
    if ( this != &other )
    {
        m_elements = other.m_elements;
    }

    return *this;
}

Span::~Span()
{
}

// Main parameterized constructor
Span::Span( unsigned int N )
    : m_elements{}
{
    m_elements.reserve( N );
}

// Main member functions

void Span::addNumber( int i )
{
    if ( m_elements.size() < m_elements.capacity() )
        m_elements.push_back( i );
    else
        throw NoMoreCapacity( "Cannot add more numbers since the object is already at its maximum capacity of " +
                              std::to_string( m_elements.capacity() ) );
}

unsigned int Span::shortestSpan()
{
    if ( m_elements.size() < 2 )
        throw SpanNotApplicable( "Span cannot be calculated since there are fewer than 2 elements present" );

    auto copyVec{ m_elements };

    std::sort( copyVec.begin(), copyVec.end() );

    unsigned int minSpan{ std::numeric_limits<unsigned int>::max() };
    unsigned int currentSpan{};
    auto         current{ copyVec.begin() };

    while ( current + 1 != copyVec.end() )
    {
        currentSpan = static_cast<long long>( *( current + 1 ) ) - ( *current );

        if ( minSpan > currentSpan )
            minSpan = currentSpan;

        if ( minSpan == 0 )
            break;

        ++current;
    }

    return minSpan;
}

unsigned int Span::longestSpan()
{
    if ( m_elements.size() < 2 )
        throw SpanNotApplicable( "Span cannot be calculated since there are fewer than 2 elements present" );

    long long minVal{ *( std::min_element( m_elements.begin(), m_elements.end() ) ) };
    long long maxVal{ *( std::max_element( m_elements.begin(), m_elements.end() ) ) };

    return ( maxVal - minVal );
}

// Exception classes constructor and what member definitions

Span::NoMoreCapacity::NoMoreCapacity( std::string_view error )
    : mError{ error }
{
}

const char* Span::NoMoreCapacity::what() const noexcept
{
    return mError.c_str();
}

Span::SpanNotApplicable::SpanNotApplicable( std::string_view error )
    : mError{ error }
{
}

const char* Span::SpanNotApplicable::what() const noexcept
{
    return mError.c_str();
}
