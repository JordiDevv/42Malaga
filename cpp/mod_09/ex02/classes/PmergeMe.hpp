#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        template <typename C>
        bool validateInput(C& container, char** rawInput);

        bool isPositiveInteger(long n);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

        bool processVector(char** rawInput);
        bool processDeque(char** rawInput);
};

#endif
