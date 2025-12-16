#include "Animal.hpp"
#include "Dog.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  Dog::Dog()
  {
    type = "Dog";
    std::cout << BLUE << DOG_CON << RESET << std::endl;
  }

  Dog::Dog(const Dog& ref) : Animal(ref)
  { std::cout << BLUE << DOG_COPY << RESET << std::endl; }

  Dog& Dog::operator=(const Dog& ref)
  {
    if (this != &ref) Animal::operator=(ref);
    return *this;
  }

  Dog::~Dog() { std::cout << BLUE << DOG_DES << RESET << std::endl; }


  // **************************************************** //
 //                        Getter                        //
// **************************************************** //

  const std::string Dog::getType() const { return type; }


  // **************************************************** //
 //                 Routine functions                    //
// **************************************************** //

  void Dog::makeSound() { std::cout << BLUE << DOG_SOUND << RESET << std::endl; }
