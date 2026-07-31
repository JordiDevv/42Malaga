#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int>    _vector;
        bool                _vectorSort;

        std::deque<int>     _deque;
        bool                _dequeSort;

        bool                _isSort;

        bool isPositiveInteger(long n);

        template <typename C>
        void printElapsedTime(clock_t startTime, clock_t endTime, C& container);

        template <typename T, typename Alloc>
        const char* containerName(const std::vector<T, Alloc>&);
        template <typename T, typename Alloc>
        const char* containerName(const std::deque<T, Alloc>&);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

        bool validateInput(char** rawInput);

        bool processVector();
        bool processDeque();

        void printData();
};

#endif
