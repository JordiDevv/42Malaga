#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  Cat::Cat()
  {
    type = "Cat";
    brain = new Brain();
    std::cout << BLUE << CAT_CON << RESET << std::endl;
  }

  Cat::Cat(const Cat& ref) : Animal(ref)
  {
    brain = new Brain(*ref.brain);
    std::cout << BLUE << CAT_COPY << RESET << std::endl;
  }

  Cat& Cat::operator=(const Cat& ref)
  {
    if (this != &ref)
    {
      Animal::operator=(ref);
      brain = new Brain(*ref.brain);
    }
    return *this;
  }

  Cat::~Cat()
  {
    delete brain;
    std::cout << BLUE << CAT_DES << RESET << std::endl;
  }


  // **************************************************** //
 //                        Getter                        //
// **************************************************** //

  const std::string Cat::getType() const { return type; }


  // **************************************************** //
 //                 Routine functions                    //
// **************************************************** //

  void Cat::makeSound() const { std::cout << BLUE << CAT_SOUND << RESET << std::endl; }
