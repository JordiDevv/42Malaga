#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExec(150) {}
    AForm::AForm(const AForm& ref)
    : name(ref.name), isSigned(ref.isSigned), gradeToSign(ref.gradeToSign), gradeToExec(ref.gradeToExec) {}

    AForm& AForm::operator=(const AForm& ref)
    {
        if (this != &ref) this->isSigned = ref.isSigned;
        return *this;
    }

    AForm::~AForm() {}


  // **************************************************** //
 //        Constructors for parameterized values         //
// **************************************************** //

    AForm::AForm(const std::string& name, const int& gradeToSign, const int& gradeToExec)
    : name(name), isSigned(false), gradeToSign(validGrade(gradeToSign)), gradeToExec(validGrade(gradeToExec))
    {}


  // **************************************************** //
 //                      Getters                         //
// **************************************************** //

    const std::string& AForm::getName() const { return name; }
    const bool& AForm::getIfSigned() const { return isSigned; }
    const int& AForm::getGradeToSign() const { return gradeToSign; }
    const int& AForm::getGradeToExec() const { return gradeToExec; }


  // **************************************************** //
 //                   Grade methods                      //
// **************************************************** //

    int AForm::validGrade(const int& grade)
    {
        if (grade < 1) throw GradeTooHighException();
        if (grade > 150) throw GradeTooLowException();
        return grade;
    }


  // **************************************************** //
 //                   Sign methods                       //
// **************************************************** //

    void AForm::beSigned(const Bureaucrat& bureaucrat)
    {
        if (bureaucrat.getGrade() <= gradeToSign) isSigned = true;
        else throw GradeTooLowException();
    }


  // **************************************************** //
 //                 Exception classes                    //
// **************************************************** //

    const char* AForm::GradeTooHighException::what() const throw()
    { return "Bureaucrat grade too high"; }

    const char* AForm::GradeTooLowException::what() const throw()
    { return "Bureaucrat grade too low"; }


  // **************************************************** //
 //             Overload for "<<" operator               //
// **************************************************** //

    std::ostream& operator<<(std::ostream& os, const AForm& form)
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
