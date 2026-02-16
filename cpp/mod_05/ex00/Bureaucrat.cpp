#include "Bureaucrat.hpp"
#include <iostream>

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
    : name(name), grade(grade) {}


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
 //                 Exception classes                    //
// **************************************************** //

    const char* Bureaucrat::GradeTooHighException::what() const throw()
    { return "Bureaucrat grade too high"; }

    const char* Bureaucrat::GradeTooLowException::what() const throw()
    { return "Bureaucrat grade too low"; }

