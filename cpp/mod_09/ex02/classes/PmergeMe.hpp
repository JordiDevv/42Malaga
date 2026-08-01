#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:
    // ********************* _vector ********************** //
        std::vector<int>    _vector;
        bool                _vectorSort;

    // ********************* _deque *********************** //
        std::deque<int>     _deque;
        bool                _dequeSort;

    // ********************** State *********************** //
        bool                _isSort;


    // ****************** Private utils ******************* //
        bool isPositiveInteger(long n);

        template <typename C1, typename C2>
        bool haveSameContent(const C1& a, const C2& b);

        template <typename T, typename Alloc>
        const char* containerName(const std::vector<T, Alloc>&);
        template <typename T, typename Alloc>
        const char* containerName(const std::deque<T, Alloc>&);

    public:
    // ************ Cannonical implementations ************ //
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

    // ********************* Parser *********************** //
        bool validateInput(char** rawInput);
        
    // ******************** Printers ********************** //
        void printData();

        template <typename C>
        void printElapsedTime(clock_t startTime, clock_t endTime, C& container);

    // ******************** Executors ********************* //
        bool processVector();
        bool processDeque();

    // ***************** Exception class ****************** //
        class NotSameContent : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif
