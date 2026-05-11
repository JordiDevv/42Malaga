#include "Span.hpp"
#include <iostream>

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

    return 0;
}
