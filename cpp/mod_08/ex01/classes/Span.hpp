#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
        unsigned int _capacity;
        std::vector<int> _container;
    public:
        Span();
        Span(const Span& span);
        Span& operator=(const Span& span);
        ~Span();

        Span(unsigned int capacity);

        void addNumber(int n);

        int shortestSpan();
        int longestSpan();

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);

        class CapacityExceededException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NotEnoughNumbersException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NotEnoughSpaceException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#include "Span.tpp"

#endif
