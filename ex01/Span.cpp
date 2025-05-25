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

unsigned int Span::shortestSpan() const
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

unsigned int Span::longestSpan() const
{
    if ( m_elements.size() < 2 )
        throw SpanNotApplicable( "Span cannot be calculated since there are fewer than 2 elements present" );

    long long minVal{ *( std::min_element( m_elements.begin(), m_elements.end() ) ) };
    long long maxVal{ *( std::max_element( m_elements.begin(), m_elements.end() ) ) };

    return ( maxVal - minVal );
}

// Print elements and get size/capacity

void Span::printElements() const
{
    std::cout << "{ ";
    for ( const auto& elem : m_elements )
        std::cout << elem << ' ';
    std::cout << "}\n";
}

void Span::printIndexRange( std::size_t first, std::size_t last ) const
{
    if ( first >= m_elements.size() || last >= m_elements.size() || first > last )
    {
        std::cout << "Invalid first/last index supplied." << '\n';
        return;
    }
    std::cout << "{ ";
    if ( first > 0 )
        std::cout << "* First " << first << " elements omitted * " << '\n';
    for ( auto i{ first }; i <= last; ++i )
        std::cout << m_elements[i] << ' ';
    if ( last > 0 && last < m_elements.size() - 1 )
        std::cout << "* Last " << m_elements.size() - last - 1 << " elements omitted * " << '\n';
    std::cout << "}\n";
}

std::size_t Span::size() const
{
    return m_elements.size();
}

std::size_t Span::capacity() const
{
    return m_elements.capacity();
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
