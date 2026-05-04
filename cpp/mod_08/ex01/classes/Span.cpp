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


  // **************************************************** //
 //                 Member functions                     //
// **************************************************** //

    void Span::addNumber(int n)
    {
        if (_container.size() >= _capacity) throw CapacityExceededException();
        _container.push_back(n);
    }


  // **************************************************** //
 //                 Exception classes                    //
// **************************************************** //

    const char* Span::CapacityExceededException::what() const throw()
    { return "Span is full"; }
