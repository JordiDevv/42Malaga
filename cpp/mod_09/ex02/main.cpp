#include "PmergeMe.hpp"
#include <iostream>

int error(const char* what = NULL)
{
    std::cerr << "Error";
    if (what) std::cerr << ": " << what;
    std::cerr << std::endl;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 3) return error();

    PmergeMe pmergeMe;

    if (!pmergeMe.validateInput(argv)) return error();

    try { pmergeMe.printData(); }
    catch(...) { return error(); }
    
    pmergeMe.processVector();
    pmergeMe.processDeque();

    try { pmergeMe.printData(); }
    catch (PmergeMe::NotSameContent& e) { return error(e.what()); }

    try { pmergeMe.printElapsedTime(); }
    catch (PmergeMe::NoContainerSort& e) { std::cerr << e.what() << std::endl; }

    return 0;
}
