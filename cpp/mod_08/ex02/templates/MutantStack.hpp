#ifndef MUTATANTSTACK_HPP
#define MUTATANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        MutantStack(const MutantStack& ref);
        MutantStack& operator=(const MutantStack& ref);
        ~MutantStack();
};

#include "MutantStack.tpp"

#endif
