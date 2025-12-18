#include "AAnimal.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  AAnimal::AAnimal() { std::cout << BLUE << ANI_CON << RESET << std::endl; }

  AAnimal::AAnimal(const AAnimal& ref) : type(ref.type)
  { std::cout << BLUE << ANI_COPY << RESET << std::endl; }

  AAnimal& AAnimal::operator=(const AAnimal& ref)
  {
    if (this != &ref) this->type = ref.type;
    return *this;
  }

  AAnimal::~AAnimal() { std::cout << BLUE << ANI_DES << RESET << std::endl; }

  
  // **************************************************** //
 //                       Getter                         //
// **************************************************** //

  const std::string AAnimal::getType() const { return type; }
