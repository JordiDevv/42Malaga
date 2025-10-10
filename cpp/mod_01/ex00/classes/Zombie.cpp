#include "Zombie.hpp"
#include <iostream>

void Zombie::announce ( void )
{
    std::cout.write(name.c_str(), name.length());
    std::cout.write(": BraiiiiiiinnnzzzZ...\n", 24);
}
