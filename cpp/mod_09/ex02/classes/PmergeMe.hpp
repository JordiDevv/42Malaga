#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe
{
    private:
        bool validateInput(std::vector<int>& input, char** rawInput);

        bool isPositiveInteger(long n);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

        bool processVector(char **rawInput);
};

#endif
