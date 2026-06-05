#include <iostream>

bool isOperator(char c)
{
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

bool validInput(int argc, char** argv)
{
    if (argc != 2) return false;

    size_t n = 0;
    size_t op = 0;
    for (size_t i = 0; argv[1][i]; i++)
    {
        if (isdigit(argv[1][i])) n++;
        else if (isOperator(argv[1][i])) op++;
        else return false;
    }

    return n - op == 1 ? true : false;
}

int main(int argc, char** argv)
{
    if (!validInput(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
