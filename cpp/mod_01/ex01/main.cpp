#include "Zombie.hpp"
#include "Zombie.h"
#include <iostream>

int main()
{
    std::cout << "Wake up and live, my son!" << std::endl;
    Zombie* zombie = newZombie("Alberto");
    zombie->announce();
    std::cout << "WTF! Who are you?" << std::endl;
    randomChump("Random Zombie");
    delete zombie;
    return (0);
}
