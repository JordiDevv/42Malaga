#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    Span span(4);

    try { span.addNumber(2); }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << span.shortestSpan() << std::endl; }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }
    try { std::cout << span.longestSpan() << std::endl; }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }

    try { span.addNumber(3); }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }
    try { span.addNumber(4); }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }
    try { span.addNumber(5); }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }
    try { span.addNumber(6); }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << span.shortestSpan() << std::endl; }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }
    try { std::cout << span.longestSpan() << std::endl; }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }

    srand(time(0));
    std::vector<int> tmp;
    for (size_t i = 0; i < 10000; i++)
        tmp.push_back(rand() % 10000);
    
    Span bigSpan(10000);
    try { bigSpan.addRange(tmp.begin(), tmp.end()); }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }

    try { bigSpan.addRange(tmp.begin(), tmp.end()); }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << bigSpan.shortestSpan() << std::endl; }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }
    try { std::cout << bigSpan.longestSpan() << std::endl; }
    catch(const std::exception& e) { std::cout << e.what() << std::endl; }

    return 0;
}
