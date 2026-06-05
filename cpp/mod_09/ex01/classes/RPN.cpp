#include "RPN.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    RPN::RPN() {}
    RPN::RPN(const RPN& ref) : _stack(ref._stack) {}

    RPN& RPN::operator=(const RPN& ref)
    {
        if (this != &ref) _stack = ref._stack;
        return *this;
    }

    RPN::~RPN() {}
