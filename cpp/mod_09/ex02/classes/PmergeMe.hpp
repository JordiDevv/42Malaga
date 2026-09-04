#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

  // **************************************************** //
 //              Template pairs containers               //
// **************************************************** //

template <typename T>
struct PairContainer;
struct Pair;

template <>
struct PairContainer< std::vector<int> >
{ typedef std::vector<Pair> type; };

template <>
struct PairContainer< std::deque<int> >
{ typedef std::deque<Pair> type; };


  // **************************************************** //
 //              Ford-Johnson data structs               //
// **************************************************** //

struct Pair
{
    int     minor;
    int     major;
    size_t  majorIndex;
};

template <typename Container>
struct FordJohnsonData
{
    typedef typename PairContainer<Container>::type PairList;

    PairList    pairs;
    int         straggler;
    bool        hasStraggler;
    Container   mainChain;
};


  // **************************************************** //
 //                     Main class                       //
// **************************************************** //

class PmergeMe
{
    private:
    // ********************* _vector ********************** //
        std::vector<int>    _vector;
        bool                _vectorSort;
        double              _timeForVector;

    // ********************* _deque *********************** //
        std::deque<int>     _deque;
        bool                _dequeSort;
        double              _timeForDeque;


    // ****************** Private utils ******************* //
        int error(const char* what = NULL);
        bool isPositiveInteger(long n);
        bool isSort();

        template <typename C1, typename C2>
        bool haveSameContent(const C1& a, const C2& b);

        double calcElapsedTime(clock_t startTime, clock_t endTime);

    // *************** Ford-Johnson helpers *************** //
        template <typename Container>
        void initData(Container& input, FordJohnsonData<Container>& data);

        template <typename Container>
        typename PairContainer<Container>::type
        sortPairsByMajor(const typename PairContainer<Container>::type& pairs);

        template <typename Container>
        void initMainChain(FordJohnsonData<Container>& data);

        template <typename Container>
        void jacobsthalInsertion(Container& mainChain, const FordJohnsonData<Container>& data);


    public:
    // ************ Cannonical implementations ************ //
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator=(const PmergeMe& ref);
        ~PmergeMe();

    // ********************* Parser *********************** //
        bool validateInput(int len, char** rawInput);
        
    // ******************** Printers ********************** //
        void printData();
        void printElapsedTime();

    // ******************** Executors ********************* //
        bool    processVector();
        bool    processDeque();
        int     run(int argc, char** argv);

    // ****************** Ford-Johnson ******************** //
        template <typename Container>
        void fordJohnson(Container& input);

    // **************** Exception clases ***************** //
        class NotSameContent : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class NoContainerSort : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif
