#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Bureaucrat::Bureaucrat() : name("Anonymous"), grade(150) {}
    Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.name), grade(ref.grade) {}

    Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
    {
        if (this != &ref) this->grade = ref.grade;
        return *this;
    }

    Bureaucrat::~Bureaucrat() {}


  // **************************************************** //
 //        Constructors for parameterized values         //
// **************************************************** //

    Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
    : name(name)
    {
        if (grade < 1) throw GradeTooHighException();
        if (grade > 150) throw GradeTooLowException();
        this->grade = grade;
    }


  // **************************************************** //
 //                      Getters                         //
// **************************************************** //

    const std::string& Bureaucrat::getName() const { return name; }
    const int& Bureaucrat::getGrade() const { return grade; }


  // **************************************************** //
 //                   Grade methods                      //
// **************************************************** //

    void Bureaucrat::incGrade()
    {
        if (grade - 1 < 1) throw GradeTooHighException();
        grade--;
    }

    void Bureaucrat::decGrade()
    {
        if (grade + 1 > 150) throw GradeTooLowException();
        grade++;
    }


  // **************************************************** //
 //                   Sign methods                       //
// **************************************************** //

    void Bureaucrat::signForm(Form& form) const
    {
        try
        {
            form.beSigned(*this);
            std::cout << name << " signed " << form.getName() << std::endl;
        }
        catch(const Form::GradeTooLowException& e)
        { 
            std::cerr   << name
                        << " couldn't sign "
                        << form.getName()
                        << " because "
                        << e.what()
                        << std::endl;
        }
    }

  // **************************************************** //
 //                 Exception classes                    //
// **************************************************** //

    const char* Bureaucrat::GradeTooHighException::what() const throw()
    { return "Bureaucrat grade too high"; }

    const char* Bureaucrat::GradeTooLowException::what() const throw()
    { return "Bureaucrat grade too low"; }


  // **************************************************** //
 //             Overload for "<<" operator               //
// **************************************************** //

    std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
    {
        return os   << bureaucrat.getName()
                    << ", bureaucrat grade "
                    << bureaucrat.getGrade()
                    << ".";
    }
