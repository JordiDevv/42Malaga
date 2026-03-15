#include "Array.hpp"
#include <cstdlib>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    template<typename T>
    Array<T>::Array() : element(NULL), _size(0) {}

    template<typename T>
    Array<T>::Array(const Array& ref) : _size(ref.size)
    {
        element = new T[_size];
        for (size_t i = 0; i < _size; i++) this->element[i] = ref.element[i];
    }

    template<typename T>
    Array<T>& Array<T>::operator=(const Array<T>& ref)
    {
        if (this != &ref)
        {
            delete[] this->element;

            this->_size = ref._size;
            this->element = new T[_size];

            for (size_t i = 0; i < _size; i++) this->element[i] = ref.element[i];
        }

        return *this;
    }

    template<typename T>
    Array<T>::~Array() { delete[] element; }


  // **************************************************** //
 //              Parameterized constructor               //
// **************************************************** //

    template<typename T>
    Array<T>::Array(size_t n) : _size(n) { element = new T[_size](); }


  // **************************************************** //
 //                       Utils                          //
// **************************************************** //

    template<typename T>
    T& Array<T>::operator[](size_t index) { return &element[index]; }

    template<typename T>
    size_t Array<T>::size() { return _size; }
