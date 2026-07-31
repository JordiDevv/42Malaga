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
        std::sort(_vector.begin(), _vector.end());
        printContainerData(_vector, true);

        return true;
    }

    bool PmergeMe::processDeque(char **rawInput)
    {
        if (!validateInput(_deque, rawInput)) return false;

        printContainerData(_deque, false);
        std::sort(_deque.begin(), _deque.end());
        printContainerData(_deque, true);

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
