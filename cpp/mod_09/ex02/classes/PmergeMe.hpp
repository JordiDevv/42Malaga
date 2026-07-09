#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe
{
    private:
        bool validateInput(std::vector<int>& input, const char** rawInput);

        bool isInteger();
        bool isPositive();
        bool isDuplicated();

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

        bool processVector(const char **rawInput);
};

#endif
