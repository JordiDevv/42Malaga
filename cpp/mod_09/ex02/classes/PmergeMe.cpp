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
        std::vector<int> input;

        if (!validateInputForVector(input, rawInput)) return false;
        return true;
    }

    bool PmergeMe::processDeque(char **rawInput)
    {
        std::deque<int> input;

        if (!validateInputForDeque(input, rawInput)) return false;
        return true;
    }

  // **************************************************** //
 //                       Parser                         //
// **************************************************** //

    bool PmergeMe::validateInputForVector(std::vector<int>& input, char** rawInput)
    {
        char* end;

        for (int i = 1; rawInput[i]; i++)
        {
            errno = 0;

            long n = strtol(rawInput[i], &end, 10);

            if (*end || errno == ERANGE || !isPositiveInteger(n))
                return false;

            input.push_back((int)n);
        }

        return true;
    }

    bool PmergeMe::validateInputForDeque(std::deque<int>& input, char** rawInput)
    {
        char* end;

        for (int i = 1; rawInput[i]; i++)
        {
            errno = 0;

            long n = strtol(rawInput[i], &end, 10);

            if (*end || errno == ERANGE || !isPositiveInteger(n))
                return false;

            input.push_back((int)n);
        }

        return true;
    }

    bool PmergeMe::isPositiveInteger(long n)
    { return n > 0 && n < INT_MAX; }
