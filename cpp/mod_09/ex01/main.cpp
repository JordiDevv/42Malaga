#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2) return false;

    RPN rpn;
    if (!rpn.validLine(argv[1]))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    int res = rpn.processLine(argv[1]);
    std::cout << res << std::endl;

    return 0;
}
