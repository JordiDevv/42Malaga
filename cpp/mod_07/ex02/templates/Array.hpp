#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T* element;

    public:
        Array();
        Array(const Array& ref);
        Array& operator=(const Array& ref);

        Array(unsigned int n);
        unsigned int size() const;
};

#include <Array.tpp>

#endif
