#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
    private:
        bool validateInputForVector(std::vector<int>& input, char** rawInput);
        bool validateInputForDeque(std::deque<int>& input, char** rawInput);

        bool isPositiveInteger(long n);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

        bool processVector(char **rawInput);
        bool processDeque(char **rawInput);
};

#endif
