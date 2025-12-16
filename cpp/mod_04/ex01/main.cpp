#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "msgs.h"
#include <iostream>

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << PURP << dog->getType() << RESET << std::endl;
    std::cout << PURP << cat->getType() << RESET << std::endl;

    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    const Animal* animal1 = new Animal();
    const Dog* dog1 = new Dog();
    const Cat* cat1 = new Cat();

    const Animal* animalCopy = new Animal(*animal1);
    const Dog* dogCopy = new Dog(*dog1);
    const Animal* catCopy = new Cat(*cat1);

    std::cout << PURP << dogCopy->getType() << RESET << std::endl;
    std::cout << PURP << catCopy->getType() << RESET << std::endl;

    catCopy->makeSound();
    dogCopy->makeSound();
    animalCopy->makeSound();

    Dog dog2 = *dogCopy;
    std::cout << PURP << dog2.getType() << RESET << std::endl;

    delete animal1;
    delete dog1;
    delete cat1;
    delete animalCopy;
    delete dogCopy;
    delete catCopy;

    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << PURP << wrongCat->getType() << RESET << std::endl;
    wrongCat->makeSound();
    delete wrongCat;

    return 0;
}
