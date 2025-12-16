#include "Brain.hpp"
#include "msgs.h"
#include "iostream"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

  Brain::Brain() { std::cout << BLUE << BRAIN_CON << RESET << std::endl; }

  Brain::Brain(const Brain& ref)
  {
    for (int i = 0; i < 100; i++) this->ideas[i] = ref.ideas[i];
    std::cout << BLUE << BRAIN_COPY << RESET << std::endl;
  }

  Brain& Brain::operator=(const Brain& ref)
  {
    if (this != &ref)
      for (int i = 0; i < 100; i++) this->ideas[i] = ref.ideas[i];
    return *this;
  }

  Brain::~Brain() { std::cout << BLUE << BRAIN_DES << RESET << std::endl; }
