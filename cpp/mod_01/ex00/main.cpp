#include "Zombie.hpp"
#include "Zombie.h"
#include <iostream>

int main()
{
    std::cout << "Wake up and live, my son!" << std::endl;
    Zombie* zombie = newZombie("Alberto");
    zombie->announce();
    delete zombie;
    return (0);
}
