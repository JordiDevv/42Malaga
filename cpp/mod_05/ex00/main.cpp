#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

int main()
{
    Bureaucrat ann;
    bool test1 = true;

    if (test1)
    {
        try { ann.decGrade(); }
        catch(const std::exception& e)
        { std::cerr << e.what() << std::endl; }
    }
    
    return (0);
}