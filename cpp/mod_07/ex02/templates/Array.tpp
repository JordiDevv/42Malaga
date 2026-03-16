#include "Array.hpp"
#include <cstdlib>
#include <exception>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    template<typename T>
    Array<T>::Array() : _element(NULL), _size(0) {}

    template<typename T>
    Array<T>::Array(const Array<T>& ref) : _size(ref._size)
    {
        _element = new T[_size];
        for (size_t i = 0; i < _size; i++) this->_element[i] = ref._element[i];
    }

    template<typename T>
    Array<T>& Array<T>::operator=(const Array<T>& ref)
    {
        if (this != &ref)
        {
            delete[] this->_element;

            this->_size = ref._size;
            this->_element = new T[_size];

            for (size_t i = 0; i < _size; i++) this->_element[i] = ref._element[i];
        }

        return *this;
    }

    template<typename T>
    Array<T>::~Array() { delete[] _element; }


  // **************************************************** //
 //              Parameterized constructor               //
// **************************************************** //

    template<typename T>
    Array<T>::Array(size_t n) : _size(n) { _element = new T[_size](); }


  // **************************************************** //
 //                       Utils                          //
// **************************************************** //

    template<typename T>
    T& Array<T>::operator[](size_t index)
    {
        if (index >= _size) throw OutOfBoundsException();
        return _element[index];
    }

    template<typename T>
    size_t Array<T>::size() const { return _size; }


  // **************************************************** //
 //                  Exception Class                     //
// **************************************************** //

    template<typename T>
    const char* Array<T>::OutOfBoundsException::what() const throw()
    { return "Trying to access invalid memory"; }
