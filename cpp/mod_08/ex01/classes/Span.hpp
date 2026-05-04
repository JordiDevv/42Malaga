#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
    private:
        unsigned int _capacity;
    public:
        Span();
        Span(const Span& span);
        Span& operator=(const Span& span);
        ~Span();

        Span(unsigned int capacity);
};

#endif
