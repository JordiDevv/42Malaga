#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    if (_container.size() + std::distance(begin, end) > _capacity)
        throw NotEnoughSpaceException();

    _container.insert(_container.end(), begin, end);
}
