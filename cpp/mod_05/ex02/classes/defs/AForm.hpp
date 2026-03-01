#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;

    protected:
        virtual void executeBehaviour() const = 0;
    
    public:
        AForm();
        AForm(const AForm& ref);
        AForm& operator=(const AForm& ref);
        virtual ~AForm();

        AForm(const std::string& name, const int& gradeToSign, const int& gradeToExec);

        const std::string& getName() const;
        const bool& getIfSigned() const;
        const int& getGradeToSign() const;
        const int& getGradeToExec() const;

        int validGrade(const int& grade);

        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;

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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
