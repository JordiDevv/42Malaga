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

        class CapacityExceededException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif
