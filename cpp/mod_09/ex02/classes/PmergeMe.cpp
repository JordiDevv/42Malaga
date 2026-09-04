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
        fordJohnson(_vector);
        std::sort(_vector.begin(), _vector.end());
        clock_t endTime = clock();

        _timeForVector  = calcElapsedTime(startTime, endTime);
        _vectorSort     = true;

        return true;
    }

    bool PmergeMe::processDeque()
    {
        clock_t startTime = clock();
        fordJohnson(_deque);
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
        FordJohnsonData<Container> data;
        initData(input, data);
        data.pairs = sortPairsByMajor<Container>(data.pairs);
        initMainChain(data);
        jacobsthalInsertion(data);
    }

    template <typename Container>
    void PmergeMe::initData(Container& input, FordJohnsonData<Container>& data)
    {
        data.straggler      = 0;
        data.hasStraggler   = false;

        size_t i;
        for (i = 0; i < input.size(); i += 2)
        {
            if (i == input.size() - 1) 
            {
                data.straggler = input[i];
                data.hasStraggler = true;
            }
            else
            {
                Pair pair;
                pair.minor      = input[i] < input[i + 1] ? input[i] : input[i + 1];
                pair.major      = input[i] >= input[i + 1] ? input[i] : input[i + 1];
                pair.majorIndex = i;
                data.pairs.push_back(pair);
            }
        }

        for (i = 0; i < data.pairs.size(); i++) data.pairs[i].majorIndex = i;
    }

    template <typename Container>
    typename PairContainer<Container>::type
    PmergeMe::sortPairsByMajor(const typename PairContainer<Container>::type& pairs)
    {
        if (pairs.size() <= 1) return pairs;

        typename PairContainer<Container>::type winners;
        typename PairContainer<Container>::type losers;

        bool hasStraggler = pairs.size() % 2 != 0;
        size_t last = pairs.size() - 1;

        for (size_t i = 0; i + 1 < pairs.size(); i += 2)
        {
            const Pair& left    = pairs[i];
            const Pair& right   = pairs[i + 1];

            if (left.major < right.major)
            {
                winners.push_back(right);
                losers.push_back(left);
            }
            else
            {
                winners.push_back(left);
                losers.push_back(right);
            }
        }

        typename PairContainer<Container>::type result =
            sortPairsByMajor<Container>(winners);

        for (size_t i = 0; i < losers.size(); ++i)
        {
            const Pair& loser = losers[i];

            typename PairContainer<Container>::type::iterator pos = result.begin();

            while (pos != result.end() && pos->major < loser.major)
            { ++pos; }

            result.insert(pos, loser);
        }

        if (hasStraggler)
        {
            const Pair& straggler = pairs[last];

            typename PairContainer<Container>::type::iterator pos = result.begin();

            while (pos != result.end() && pos->major < straggler.major)
            { ++pos; }

            result.insert(pos, straggler);
        }

        return result;
    }

    template <typename Container>
    void PmergeMe::initMainChain(FordJohnsonData<Container>& data)
    {
        data.mainChain.push_back(data.pairs[0].minor);

        for (size_t i = 0; i < data.pairs.size(); i++)
        {
            data.mainChain.push_back(data.pairs[i].major);
            data.pairs[i].majorIndex = i + 1;
        }
    }

    template <typename Container>
    void PmergeMe::jacobsthalInsertion(FordJohnsonData<Container>& data)
    {
        size_t prev         = 1;
        size_t jacobsthal   = 3;

        insertMinor(data.mainChain, data, prev);

        while (prev < data.pairs.size())
        {
            size_t current = jacobsthal;

            if (current >= data.pairs.size())
                current = data.pairs.size() - 1;

            while (current > prev)
            {
                insertMinor(data.mainChain, data, current);
                --current;
            }

            size_t nextPrev = jacobsthal;
            jacobsthal      += prev * 2;
            prev            = nextPrev;
        }
    }

    template <typename Container>
    void PmergeMe::insertMinor(Container& mainChain, FordJohnsonData<Container>& data, size_t current)
    {
        Pair pair       = data.pairs[current];
        size_t low      = 0;
        size_t upper    = pair.majorIndex;

        while (low < upper)
        {
            size_t middle = low + (upper - low) / 2;

            if (mainChain[middle] < pair.minor) low = middle + 1;
            else upper = middle;
        }

        size_t insertIndex = low;
        mainChain.insert(mainChain.begin() + insertIndex, pair.minor);

        for (size_t i = insertIndex; i < data.pairs.size(); ++i)
        { data.pairs[i].majorIndex++; }
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
