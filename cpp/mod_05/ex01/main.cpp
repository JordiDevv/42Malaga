#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

int main()
{
    Form* formB32 = 0;
    try
    {
        formB32 = new Form("formB32", 150, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << formB32 << std::endl;

    return (0);
}
