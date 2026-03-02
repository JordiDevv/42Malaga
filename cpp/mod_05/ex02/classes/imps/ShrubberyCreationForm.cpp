#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

    ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : AForm(ref), target(ref.target) {}

    ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
    {
        if (this != &ref)
        {
            AForm::operator=(ref);
            this->target = ref.target;
        }
        return *this;
    }

    ShrubberyCreationForm::~ShrubberyCreationForm() {}


  // **************************************************** //
 //              Parameterized constructors              //
// **************************************************** //

    ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}


  // **************************************************** //
 //                  Actions methods                     //
// **************************************************** //

    void ShrubberyCreationForm::executeBehaviour() const
    {
        std::string filename = target + "_shrubbery";
        std::ofstream file(filename.c_str());

        if (!file.is_open()) throw std::ios_base::failure("Failed to create shrubbery file");

        file    << "   1   " << std::endl
                << "  111  " << std::endl
                << " 11111 " << std::endl
                << "   1   " << std::endl;
        file.close();
    }
