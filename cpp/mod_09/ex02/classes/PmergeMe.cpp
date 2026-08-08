#include "PmergeMe.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <iostream>
#include <algorithm>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    PmergeMe::PmergeMe() : _vectorSort(false), _dequeSort(false) {}

    PmergeMe::PmergeMe(const PmergeMe& ref)
    : _vectorSort(ref._vectorSort), _dequeSort(ref._dequeSort) {}

    PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
    {
        if (this != &ref)
        {
            _vectorSort = ref._vectorSort;
            _dequeSort = ref._dequeSort;
        }

        return *this;
    }

    PmergeMe::~PmergeMe() {}


  // **************************************************** //
 //                       Parser                         //
// **************************************************** //

    bool PmergeMe::validateInput(int len, char** rawInput)
    {
        if (len < 3) return false;

        char* end;

        for (int i = 1; rawInput[i]; i++)
        {
            errno = 0;

            long n = strtol(rawInput[i], &end, 10);

            if (*end || errno == ERANGE || !isPositiveInteger(n))
                return false;

            _vector.push_back((int)n);
            _deque.push_back((int)n);
        }

        return true;
    }


  // **************************************************** //
 //                      Printers                        //
// **************************************************** //

    void PmergeMe::printData()
    {
        if (!haveSameContent(_vector, _deque)) throw NotSameContent();

        std::cout << (!isSort() ? "Before:" : "After:");

        std::vector<int>::const_iterator it;
        for (it = _vector.begin(); it != _vector.end(); ++it)
        { std::cout << " " << *it; }

        std::cout << std::endl;
    }

    void PmergeMe::printElapsedTime()
    {
        if (!_vectorSort && !_dequeSort) throw NoContainerSort();

        if (_vectorSort)
        {
            std::cout   << "Time to process a range of "
                        << _vector.size()
                        << " elements with std::vector : "
                        << _timeForVector
                        << " us"
                        << std::endl;
        }

        if (_dequeSort)
        {
            std::cout   << "Time to process a range of "
                        << _deque.size()
                        << " elements with std::deque : "
                        << _timeForDeque
                        << " us"
                        << std::endl;
        }
    }


  // **************************************************** //
 //                      Executors                       //
// **************************************************** //

    bool PmergeMe::processVector()
    {
        clock_t startTime = clock();
        std::sort(_vector.begin(), _vector.end());
        clock_t endTime = clock();

        _timeForVector  = calcElapsedTime(startTime, endTime);
        _vectorSort     = true;

        return true;
    }

    bool PmergeMe::processDeque()
    {
        clock_t startTime = clock();
        std::sort(_deque.begin(), _deque.end());
        clock_t endTime = clock();

        _timeForDeque   = calcElapsedTime(startTime, endTime);
        _dequeSort      = true;

        return true;
    }

    int PmergeMe::run(int argc, char** argv)
    {
        if (!validateInput(argc, argv)) return error();

        try { printData(); }
        catch (NotSameContent& e) { return error(e.what()); }
        
        processVector();
        processDeque();

        try { printData(); }
        catch (NotSameContent& e) { return error(e.what()); }

        try { printElapsedTime(); }
        catch (NoContainerSort& e) { std::cerr << e.what() << std::endl; }

        return 0;
    }


  // **************************************************** //
 //                    Ford-Johnson                      //
// **************************************************** //

    template <typename Container>
    void PmergeMe::fordJohnson(Container& input)
    {
        // ...
    }

    
  // **************************************************** //
 //                   Private utils                      //
// **************************************************** //

    int PmergeMe::error(const char* what)
    {
        std::cerr << "Error";
        if (what) std::cerr << ": " << what;
        std::cerr << std::endl;
        return 1;
    }

    bool PmergeMe::isSort() { return _vectorSort && _dequeSort; }

    bool PmergeMe::isPositiveInteger(long n)
    { return n > 0 && n < INT_MAX; }

    template <typename C1, typename C2>
    bool PmergeMe::haveSameContent(const C1& a, const C2& b)
    { return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin()); }

    double PmergeMe::calcElapsedTime(clock_t startTime, clock_t endTime)
    { return static_cast<double>(endTime - startTime) * 1000000.0 / CLOCKS_PER_SEC; }


  // **************************************************** //
 //                  Exception class                     //
// **************************************************** //

    const char* PmergeMe::NotSameContent::what() const throw()
    { return "Have been an error comparing both containers content"; }

    const char* PmergeMe::NoContainerSort::what() const throw()
    { return "None of the containers have been sort yet"; }
