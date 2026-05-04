#include "Span.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Span::Span() : _capacity(0) {}
    Span::Span(const Span& span) : _capacity(span._capacity) {}

    Span& Span::operator=(const Span& span)
    {
        if (this != &span) this->_capacity = span._capacity;
        return *this;
    }

    Span::~Span() {}


  // **************************************************** //
 //              Parameterized constructors              //
// **************************************************** //

    Span::Span(unsigned int capacity) : _capacity(capacity) {}
