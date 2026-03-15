#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* _element;
        size_t _size;

    public:
        Array();
        Array(const Array& ref);
        Array& operator=(const Array& ref);
        ~Array();

        Array(size_t n);

        T& operator[](size_t index);
        size_t size() const;
};

#include "Array.tpp"

#endif
