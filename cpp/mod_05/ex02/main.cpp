#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

int main()
{
    // BAD INITIALIZING FORM
    Form* formB32 = 0;
    try
    { formB32 = new Form("formB32", 150, 151); }
    catch(const std::exception& e)
    { std::cerr << e.what() << std::endl; }
    if (formB32) std::cout << *formB32 << std::endl;
    else std::cerr << "Form wasn't well initialized" << std::endl;

    // SUCCESS INITIALIZING FORM
    try
    { formB32 = new Form("B32", 150, 150); }
    catch(const std::exception& e)
    { std::cerr << e.what() << std::endl; }
    if (formB32) std::cout << *formB32 << std::endl;
    else std::cerr << "Form wasn't well initialized" << std::endl;

    // INITIALIZNG ONE BUREAUCRAT
    Bureaucrat* severus = 0;
    try { severus = new Bureaucrat("Severus", 150); }
    catch(const std::exception& e)
    { std::cerr << e.what() << std::endl; }

    // SUCCESS SIGNING FORM
    if (severus && formB32)
    {
        severus->signForm(*formB32);
        std::cout << *formB32 << std::endl;
    }
    else std::cerr << "Bureaucrat or form wasn't well initialized" << std::endl;

    // INITILIZING HIGH GRADE FORM
    Form* formB33 = 0;
    try
    { formB33 = new Form("B33", 149, 150); }
    catch(const std::exception& e)
    { std::cerr << e.what() << std::endl; }
    if (formB33) std::cout << *formB33 << std::endl;
    else std::cerr << "Form wasn't well initialized" << std::endl;

    // TRY TO SIGN A HIGHER FORM
    if (severus && formB33)
    {
        severus->signForm(*formB33);
        std::cout << *formB33 << std::endl;
    }
    else std::cerr << "Bureaucrat or form wasn't well initialized" << std::endl;

    // INC SERVERUS GRADE FOR A SUCCESS SIGNING
    if (severus) severus->incGrade();
    if (formB33)
    {
        severus->signForm(*formB33);
        std::cout << *formB33 << std::endl;
    }

    // FREE ALL THE USED POINTERS
    if (formB32) delete formB32;
    if (severus) delete severus;
    if (formB33) delete formB33;

    return (0);
}
