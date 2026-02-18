#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;
    
    public:
        Form();
        Form(const Form& ref);
        Form& operator=(const Form& ref);
        ~Form();

        Form(const std::string& name, const int& gradeToSign, const int& gradeToExec);

        const std::string& getName() const;
        const bool& getIfSigned() const;
        const int& getGradeToSign() const;
        const int& getGradeToExec() const;

        void beSigned(const Bureaucrat& Bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif