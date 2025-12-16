#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "msgs.h"
#include <iostream>

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    return 0;
}
