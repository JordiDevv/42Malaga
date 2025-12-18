#include "AMateria.hpp"
#include "ICharacter.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    AMateria::AMateria() {}
    AMateria::AMateria(const AMateria& ref) : type(ref.type) {}

    AMateria& AMateria::operator=(const AMateria& ref)
    {
        (void)ref;
        return *this;
    }

    AMateria::~AMateria() {}


  // **************************************************** //
 //               Parameterized Constructor              //
// **************************************************** //

    AMateria::AMateria(const std::string& type) : type(type) {}


  // **************************************************** //
 //                       Getter                         //
// **************************************************** //

    const std::string& AMateria::getType() const { return type; }


  // **************************************************** //
 //                   Virtual Methods                    //
// **************************************************** //

    