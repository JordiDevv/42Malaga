#include "PmergeMe.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    PmergeMe::PmergeMe() {}
    PmergeMe::PmergeMe(const PmergeMe& ref) {}

    PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
    { if (this != &ref) return *this; }

    PmergeMe::~PmergeMe() {}


  // **************************************************** //
 //                      Executors                       //
// **************************************************** //

    bool PmergeMe::processVector(const char **rawInput)
    {
        std::vector<int> input;

        if (!validateInput(input, rawInput)) return false;
    }


  // **************************************************** //
 //                       Parser                         //
// **************************************************** //

    bool PmergeMe::validateInput(std::vector<int>& input, const char** rawInput)
    {
        for (int i = 1; rawInput[i]; i++)
        {
            return true;
        }

        return true;
    }

    bool PmergeMe::isInteger()
    {
        return true;
    }

    bool PmergeMe::isPositive()
    {
        return true;
    }

    bool PmergeMe::isDuplicated()
    {
        return true;
    }
