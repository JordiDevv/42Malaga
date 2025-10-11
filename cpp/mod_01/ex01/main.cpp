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

    std::cout << "Wait, wait... Something's going wrong" << std::endl;
    Zombie* zombies = zombieHorde(7, "Felipe");
    for (int i = 0; i < 7; i++)
        zombies[i].announce();
    std::cout << "Go back to the darkness where you came for!!" << std::endl;
    delete[] zombies;

    return (0);
}
