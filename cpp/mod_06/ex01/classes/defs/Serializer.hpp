#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "DataStruct.hpp"
#include <cstdint>

class Serializer
{
    private:
        Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
