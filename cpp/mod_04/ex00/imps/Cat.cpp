#include "Animal.hpp"
#include "Cat.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  Cat::Cat()
  {
    type = "Cat";
    std::cout << BLUE << CAT_CON << RESET << std::endl;
  }

  Cat::Cat(const Cat& ref) : Animal(ref)
  { std::cout << BLUE << CAT_COPY << RESET << std::endl; }

  Cat& Cat::operator=(const Cat& ref)
  {
    if (this != &ref) Animal::operator=(ref);
    return *this;
  }

  Cat::~Cat() { std::cout << BLUE << CAT_DES << RESET << std::endl; }


  // **************************************************** //
 //                        Getter                        //
// **************************************************** //

  const std::string Cat::getType() const { return type; }


  // **************************************************** //
 //                 Routine functions                    //
// **************************************************** //

  void Cat::makeSound() { std::cout << BLUE << CAT_SOUND << RESET << std::endl; }
