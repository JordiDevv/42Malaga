#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;

    if (!pmergeMe.validateInput(argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    pmergeMe.printData();

    pmergeMe.processVector();
    pmergeMe.processDeque();

    pmergeMe.printData();

    return 0;
}
