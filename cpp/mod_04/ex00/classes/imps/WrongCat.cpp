#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  WrongCat::WrongCat()
  {
    type = "WrongCat";
    std::cout << BLUE << W_CAT_CON << RESET << std::endl;
  }

  WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
  { std::cout << BLUE << W_CAT_COPY << RESET << std::endl; }

  WrongCat& WrongCat::operator=(const WrongCat& ref)
  {
    if (this != &ref) WrongAnimal::operator=(ref);
    return *this;
  }

  WrongCat::~WrongCat() { std::cout << BLUE << W_CAT_DES << RESET << std::endl; }


  // **************************************************** //
 //                        Getter                        //
// **************************************************** //

  const std::string WrongCat::getType() const { return type; }
