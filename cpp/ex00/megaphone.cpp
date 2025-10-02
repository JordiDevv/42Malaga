#include <iostream>

int main (int argc, char **argv)
{
    if (argv)
        argc = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
}