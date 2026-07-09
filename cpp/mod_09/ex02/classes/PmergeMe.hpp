#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
    private:
        bool validateInput();

        bool isPositive();
        bool isDuplicated();

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

        bool processVector();
};

#endif
