#include "Animal.hpp"
#include "msgs.h"
#include "iostream"

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

   Animal::Animal() { std::cout << BLUE << ANI_CON << RESET << std::endl; }

   Animal::Animal(const Animal& ref) : type(ref.type)
   { std::cout << BLUE << ANI_COPY << RESET << std::endl; }

   Animal& Animal::operator=(const Animal& ref)
   {
      if (this != &ref) this->type = ref.type;
      return *this;
   }

   Animal::~Animal() { std::cout << BLUE << ANI_DES << RESET << std::endl; }

   