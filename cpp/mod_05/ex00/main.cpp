#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

int main()
{
    Bureaucrat ann;
    bool test1 = false;
    bool test2 = false;

    if (test1)
    {
        try { ann.decGrade(); }
        catch(const std::exception& e)
        { std::cerr << e.what() << std::endl; }
    }

    std::cout << ann << std::endl;

    Bureaucrat ann2(ann);

    try { ann2.incGrade(); }
    catch(const std::exception& e)
    { std::cerr << e.what() << std::endl; }

    if (test2)
    {
        for (int i = ann2.getGrade(); i > 0; i--)
        {
            try { ann2.incGrade(); }
            catch(const std::exception& e)
            { std::cerr << e.what() << std::endl; }
        }
    }

    std::cout << ann2 << std::endl;

    ann2 = ann;
    std::cout << ann2 << std::endl;

    Bureaucrat alfonso("Alfonso", 1);
    std::cout << alfonso << std::endl;
    Bureaucrat mafalda("Mafalda", 0);
    
    return (0);
}