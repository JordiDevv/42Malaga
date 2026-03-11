#include "Serializer.hpp"
#include "DataStruct.hpp"
#include <stdint.h>
#include <iostream>

int main()
{
    Data data;

    uintptr_t raw = Serializer::serialize(&data);
    Data* dataPtr = Serializer::deserialize(raw);

    dataPtr == &data ? std::cout << "Okay" : std::cout << "Not Okay";
    std::cout << std::endl;

    return 0;
}
