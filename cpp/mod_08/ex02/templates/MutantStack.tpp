#include "MutantStack.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    template<typename T, typename Container>
    MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

    template<typename T, typename Container>
    MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& ref)
    : std::stack<T, Container>(ref) {}

    template<typename T, typename Container>
    MutantStack<T, Container>& MutantStack<T, Container>::operator=
        (const MutantStack<T, Container>& ref)
    {
        if (this != &ref) std::stack<T, Container>::operator=(ref);
        return *this;
    }

    template<typename T, typename Container>
    MutantStack<T, Container>::~MutantStack() {}


  // **************************************************** //
 //                     Iterators                        //
// **************************************************** //

    template<typename T, typename Container>
    typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
    { return this->c.begin(); }

    template<typename T, typename Container>
    typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
    { return this->c.end(); }

    template<typename T, typename Container>
    typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
    { return this->c.begin(); }

    template<typename T, typename Container>
    typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
    { return this->c.end(); }
