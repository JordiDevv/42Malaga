#include "PmergeMe.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>

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
        if (!validateInputForVector(rawInput)) return false;
        return true;
    }

    bool PmergeMe::processDeque(char **rawInput)
    {
        if (!validateInputForDeque(rawInput)) return false;
        return true;
    }

  // **************************************************** //
 //                       Parser                         //
// **************************************************** //

    bool PmergeMe::validateInputForVector(char** rawInput)
    {
        char* end;

        for (int i = 1; rawInput[i]; i++)
        {
            errno = 0;

            long n = strtol(rawInput[i], &end, 10);

            if (*end || errno == ERANGE || !isPositiveInteger(n))
                return false;

            _vectorInput.push_back((int)n);
        }

        return true;
    }

    bool PmergeMe::validateInputForDeque(char** rawInput)
    {
        char* end;

        for (int i = 1; rawInput[i]; i++)
        {
            errno = 0;

            long n = strtol(rawInput[i], &end, 10);

            if (*end || errno == ERANGE || !isPositiveInteger(n))
                return false;

            _dequeInput.push_back((int)n);
        }

        return true;
    }

    bool PmergeMe::isPositiveInteger(long n)
    { return n > 0 && n < INT_MAX; }
