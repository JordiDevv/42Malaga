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
