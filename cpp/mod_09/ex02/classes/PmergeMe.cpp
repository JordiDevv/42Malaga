#include "PmergeMe.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <iostream>
#include <algorithm>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    PmergeMe::PmergeMe() : _vectorSort(false), _dequeSort(false), _isSort(false) {}

    PmergeMe::PmergeMe(const PmergeMe& ref)
    : _vectorSort(ref._vectorSort), _dequeSort(ref._dequeSort), _isSort(ref._isSort) {}

    PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
    {
        if (this != &ref)
        {
            _vectorSort = ref._vectorSort;
            _dequeSort = ref._dequeSort;
            _isSort = ref._isSort;
        }

        return *this;
    }

    PmergeMe::~PmergeMe() {}


  // **************************************************** //
 //                      Executors                       //
// **************************************************** //

    bool PmergeMe::processVector()
    {
        clock_t startTime = clock();
        std::sort(_vector.begin(), _vector.end());
        clock_t endTime = clock();

        printElapsedTime(startTime, endTime, _vector);

        return true;
    }

    bool PmergeMe::processDeque()
    {
        clock_t startTime = clock();
        std::sort(_deque.begin(), _deque.end());
        clock_t endTime = clock();

        printElapsedTime(startTime, endTime, _deque);

        return true;
    }


  // **************************************************** //
 //                       Parser                         //
// **************************************************** //

    bool PmergeMe::validateInput(char** rawInput)
    {
        char* end;

        for (int i = 1; rawInput[i]; i++)
        {
            errno = 0;

            long n = strtol(rawInput[i], &end, 10);

            if (*end || errno == ERANGE || !isPositiveInteger(n))
                return false;

            _vector.push_back((int)n);
            _deque.push_back((int)n);
        }

        return true;
    }

    bool PmergeMe::isPositiveInteger(long n)
    { return n > 0 && n < INT_MAX; }


      // **************************************************** //
     //                      Printers                        //
    // **************************************************** //

    void PmergeMe::printData()
    {
        std::cout << (!_isSort ? "Before:" : "After:");

        std::vector<int>::const_iterator it;
        for (it = _vector.begin(); it != _vector.end(); ++it)
        { std::cout << " " << *it; }

        std::cout << std::endl;
    }

    template <typename C>
    void PmergeMe::printElapsedTime
    (clock_t startTime, clock_t endTime, C& container)
    {
        clock_t elapsedTicks = endTime - startTime;
        double elapsedTime = static_cast<double>(elapsedTicks) * 1000000.0 / CLOCKS_PER_SEC;

        std::cout   << "Time to process a range of "
                    << container.size()
                    << " elements with std::"
                    << containerName(container)
                    << " : " 
                    << elapsedTime
                    << " us"
                    << std::endl;
    }

    template <typename T, typename Alloc>
    const char* PmergeMe::containerName(const std::vector<T, Alloc>&)
    { return "vector"; }

    template <typename T, typename Alloc>
    const char* PmergeMe::containerName(const std::deque<T, Alloc>&)
    { return "deque"; }
