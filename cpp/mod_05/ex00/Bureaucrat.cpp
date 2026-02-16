#include "Bureaucrat.hpp"

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