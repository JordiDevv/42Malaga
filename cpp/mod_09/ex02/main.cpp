#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    argv = argv;
    if (argc < 3)
    {
        std::cerr << "Error" << std::endl;
        return 0;
    }

    PmergeMe pmergeMe;

    if (!pmergeMe.processVector(argv))
    {
        std::cerr << "Error" << std::endl;
        return 0;
    }

    if (!pmergeMe.processDeque(argv))
    {
        std::cerr << "Error" << std::endl;
        return 0;
    }

    return 0;
}
