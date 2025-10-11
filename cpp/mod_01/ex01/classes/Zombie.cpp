#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}
Zombie::Zombie(std::string name) { this->name = name; }
Zombie::~Zombie() { std::cout << name << " has been purified." << std::endl; }

void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
