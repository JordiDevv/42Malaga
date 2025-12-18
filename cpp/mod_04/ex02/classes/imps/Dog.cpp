#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  Dog::Dog()
  {
    type = "Dog";
    brain = new Brain();
    std::cout << BLUE << DOG_CON << RESET << std::endl;
  }

  Dog::Dog(const Dog& ref) : AAnimal(ref)
  {
    brain = new Brain(*ref.brain);
    std::cout << BLUE << DOG_COPY << RESET << std::endl;
  }

  Dog& Dog::operator=(const Dog& ref)
  {
    if (this != &ref)
    {
      AAnimal::operator=(ref);
      delete brain;
      brain = new Brain(*ref.brain);
    }
    return *this;
  }

  Dog::~Dog()
  {
    delete brain;
    std::cout << BLUE << DOG_DES << RESET << std::endl;
  }


  // **************************************************** //
 //                  Getters & Setters                   //
// **************************************************** //

  const std::string Dog::getType() const { return type; }

  const std::string Dog::getIdea(const int& i) const
  { return brain->getIdea(i); }

  void Dog::setIdea(const int& i, const std::string& idea)
  { brain->setIdea(i, idea); }


  // **************************************************** //
 //                 Routine functions                    //
// **************************************************** //

  void Dog::makeSound() const { std::cout << BLUE << DOG_SOUND << RESET << std::endl; }
