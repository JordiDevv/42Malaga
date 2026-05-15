#include "Span.hpp"
#include <cstddef>
#include <algorithm>

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

    int Span::shortestSpan()
    {
        if (_container.size() < 2) throw NotEnoughNumbersException();

        std::vector<int> tmp(_container);
        std::sort(tmp.begin(), tmp.end());

        int minDiff = tmp[1] - tmp[0];
        for (size_t i = 1; i < tmp.size() - 1; i++)
        {
            int tmpDiff = tmp[i + 1] - tmp[i];
            if (tmpDiff < minDiff) minDiff = tmpDiff;
        }

        return minDiff;
    }

    int Span::longestSpan()
    {
        if (_container.size() < 2) throw NotEnoughNumbersException();
        
        int smallest = _container[0];
        int biggest = _container[0];
        for (size_t i = 1; i < _container.size(); i++)
        {
            if (_container[i] < smallest) smallest = _container[i];
            if (_container[i] > biggest) biggest = _container[i];
        }

        return biggest - smallest;
    }

  // **************************************************** //
 //                 Exception classes                    //
// **************************************************** //

    const char* Span::CapacityExceededException::what() const throw()
    { return "Span is full"; }

    const char* Span::NotEnoughNumbersException::what() const throw()
    { return "There are less than two numbers"; }

    const char* Span::NotEnoughSpaceException::what() const throw()
    { return "Not enough space"; }
