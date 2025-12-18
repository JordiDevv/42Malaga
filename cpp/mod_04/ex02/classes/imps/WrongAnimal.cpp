#include "WrongAnimal.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  WrongAnimal::WrongAnimal() { std::cout << BLUE << W_ANI_CON << RESET << std::endl; }

  WrongAnimal::WrongAnimal(const WrongAnimal& ref) : type(ref.type)
  { std::cout << BLUE << W_ANI_COPY << RESET << std::endl; }

  WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
  {
    if (this != &ref) this->type = ref.type;
    return *this;
  }

  WrongAnimal::~WrongAnimal() { std::cout << BLUE << W_ANI_DES << RESET << std::endl; }

  
  // **************************************************** //
 //                       Getter                         //
// **************************************************** //

  const std::string WrongAnimal::getType() const { return type; }


  // **************************************************** //
 //                 Routine functions                    //
// **************************************************** //

  void WrongAnimal::makeSound() const { std::cout << BLUE << W_ANI_SOUND << RESET << std::endl; }
