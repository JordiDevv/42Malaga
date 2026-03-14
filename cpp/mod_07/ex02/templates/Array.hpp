#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* element;
        size_t size;

    public:
        Array();
        Array(const Array& ref);
        Array& operator=(const Array& ref);
        ~Array();

        Array(unsigned int n);

        T& operator[](size_t index)
        size_t size() const;
};

#include <Array.tpp>

#endif
