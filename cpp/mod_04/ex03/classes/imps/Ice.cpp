#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include <iostream>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Ice::Ice() : AMateria("ice") {}
    Ice::Ice(const Ice& ref) : AMateria(ref.type) {}

    Ice& Ice::operator=(const Ice& ref)
    {
        (void)ref;
        return *this;
    }

    Ice::~Ice() {}


  // **************************************************** //
 //                   Virtual Methods                    //
// **************************************************** //

    AMateria* Ice::clone() const { return new Ice(); }
    void Ice::use(ICharacter& target)
    { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }
