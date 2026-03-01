#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    protected:
        virtual void executeBehaviour() const;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& ref);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string& target);
};

#endif