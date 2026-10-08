#include "RPN.hpp"
#include <iostream>

int error()
{
    std::cerr << "Error" << std::endl;
    return 1;
}

int main(int argc, char** argv)
{
    if (argc != 2) return false;

    RPN rpn;
    if (!rpn.validLine(argv[1])) return error();

    if (!rpn.processLine(argv[1])) return error();
    else std::cout << rpn.getTop() << std::endl;

    return 0;
}
