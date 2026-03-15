#include "Array.hpp"
#include <cstdlib>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    template<typename T>
    Array<T>::Array() : element(NULL), size(0) {}

    template<typename T>
    Array<T>::Array(const Array& ref) : size(ref.size)
    {
        element = new T[size];
        for (size_t i = 0; i < size; i++) this->element[i] = ref.element[i];
    }

    template<typename T>
    Array<T>& Array<T>::operator=(const Array<T>& ref)
    {
        if (this != &ref)
        {
            delete[] this->element;

            this->size = ref.size;
            this->element = new T[size];

            for (size_t i = 0; i < size; i++) this->element[i] = ref.element[i];
        }

        return *this;
    }

    template<typename T>
    Array<T>::~Array() { delete[] element; }
