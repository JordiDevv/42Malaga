#include "iter.hpp"
#include <iostream>

void inc(int& x) { x++; }
void print(int arg) { std::cout << arg << " "; }

int main()
{
    int arr[3] = { 1, 2, 3 };

    ::iter(arr, 3, inc);
    ::iter(arr, 3, print);
    std::cout << std::endl;

    const int carr[3] = { 4, 5, 6 };

    ::iter(carr, 3, print);
    std::cout << std::endl;

    return 0;
}
