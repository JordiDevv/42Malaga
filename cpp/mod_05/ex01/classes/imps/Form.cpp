#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExec(150) {}
    Form::Form(const Form& ref)
    : name(ref.name), isSigned(ref.isSigned), gradeToSign(ref.gradeToSign), gradeToExec(ref.gradeToExec) {}

    Form& Form::operator=(const Form& ref)
    {
        if (this != &ref) this->isSigned = ref.isSigned;
        return *this;
    }

    Form::~Form() {}


  // **************************************************** //
 //        Constructors for parameterized values         //
// **************************************************** //

    Form::Form(const std::string& name, const int& gradeToSign, const int& gradeToExec)
    : name(name), isSigned(false), gradeToSign(validGrade(gradeToSign)), gradeToExec(validGrade(gradeToExec))
    {}


  // **************************************************** //
 //                      Getters                         //
// **************************************************** //

    const std::string& Form::getName() const { return name; }
    const bool& Form::getIfSigned() const { return isSigned; }
    const int& Form::getGradeToSign() const { return gradeToSign; }
    const int& Form::getGradeToExec() const { return gradeToExec; }


  // **************************************************** //
 //                   Grade methods                      //
// **************************************************** //

    int Form::validGrade(const int& grade)
    {
        if (grade < 1) throw GradeTooHighException();
        if (grade > 150) throw GradeTooLowException();
        return grade;
    }


  // **************************************************** //
 //                   Sign methods                       //
// **************************************************** //

    void Form::beSigned(const Bureaucrat& bureaucrat)
    {
        if (bureaucrat.getGrade() <= gradeToSign) isSigned = true;
        else GradeTooLowException();
    }


  // **************************************************** //
 //                 Exception classes                    //
// **************************************************** //

    const char* Form::GradeTooHighException::what() const throw()
    { return "Bureaucrat grade too high"; }

    const char* Form::GradeTooLowException::what() const throw()
    { return "Bureaucrat grade too low"; }


  // **************************************************** //
 //             Overload for "<<" operator               //
// **************************************************** //

    std::ostream& operator<<(std::ostream& os, const Form& form)
    {
        return os   << "Form: "
                    << form.getName()
                    << ", with bureaucrat grade "
                    << form.getGradeToSign()
                    << " to be signed, and bureaucrat grade "
                    << form.getGradeToExec()
                    << " to be executed, is "
                    << (form.getIfSigned() ? "signed." : "not signed.");
    }
