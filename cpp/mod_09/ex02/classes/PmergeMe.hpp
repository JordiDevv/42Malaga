#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

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
