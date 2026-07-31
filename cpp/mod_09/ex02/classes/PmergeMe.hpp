#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        template <typename C>
        bool validateInput(C& container, char** rawInput);

        bool isPositiveInteger(long n);

        template <typename C>
        void printContainerData(C& container, bool isSort);
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

        bool processVector(char** rawInput);
        bool processDeque(char** rawInput);
};

#endif
