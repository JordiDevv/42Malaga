#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Cure::Cure() : AMateria("cure") {}
    Cure::Cure(const Cure& ref) : AMateria(ref.type) {}

    Cure& Cure::operator=(const Cure& ref)
    {
        (void)ref;
        return *this;
    }

    Cure::~Cure() {}


  // **************************************************** //
 //                   Virtual Methods                    //
// **************************************************** //

    