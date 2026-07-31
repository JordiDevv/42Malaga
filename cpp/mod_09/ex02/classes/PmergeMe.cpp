#include "PmergeMe.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <iostream>
#include <algorithm>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    PmergeMe::PmergeMe() {}
    PmergeMe::PmergeMe(const PmergeMe& ref) { (void)ref; }

    PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
    {
        (void)ref;
        return *this;
    }

    PmergeMe::~PmergeMe() {}


  // **************************************************** //
 //                      Executors                       //
// **************************************************** //

    bool PmergeMe::processVector(char **rawInput)
    {
        if (!validateInput(_vector, rawInput)) return false;

        printContainerData(_vector, false);

        clock_t startTime = clock();
        std::sort(_vector.begin(), _vector.end());
        clock_t endTime = clock();

        printContainerData(_vector, true);

        printElapsedTime(startTime, endTime, _vector);

        return true;
    }

    bool PmergeMe::processDeque(char **rawInput)
    {
        if (!validateInput(_deque, rawInput)) return false;

        printContainerData(_deque, false);
    
        clock_t startTime = clock();
        std::sort(_deque.begin(), _deque.end());
        clock_t endTime = clock();

        printContainerData(_deque, true);

        printElapsedTime(startTime, endTime, _deque);

        return true;
    }


  // **************************************************** //
 //                       Parser                         //
// **************************************************** //

    template<typename C>
    bool PmergeMe::validateInput(C& container, char** rawInput)
    {
        char* end;

        for (int i = 1; rawInput[i]; i++)
        {
            errno = 0;

            long n = strtol(rawInput[i], &end, 10);

            if (*end || errno == ERANGE || !isPositiveInteger(n))
                return false;

            container.push_back((int)n);
        }

        return true;
    }

    bool PmergeMe::isPositiveInteger(long n)
    { return n > 0 && n < INT_MAX; }


      // **************************************************** //
     //                      Printers                        //
    // **************************************************** //

    template <typename C>
    void PmergeMe::printContainerData(C& container, bool isSort)
    {
        std::cout << (!isSort ? "Before:" : "After:");

        typename C::const_iterator it;
        for (it = container.begin(); it != container.end(); ++it)
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
