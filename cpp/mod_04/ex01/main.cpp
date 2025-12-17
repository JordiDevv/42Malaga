#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "msgs.h"
#include <iostream>

int main()
{
    std::cout << "=== Polymorphism test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n=== Array of Animals ===" << std::endl;
    const Animal* animals[4];

    for (int k = 0; k < 2; k++)
        animals[k] = new Dog();
    for (int k = 2; k < 4; k++)
        animals[k] = new Cat();

    for (int k = 0; k < 4; k++)
        delete animals[k];

    std::cout << "\n=== Deep copy test ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "I want food");

    Dog copy(basic);
    copy.setIdea(0, "I want sleep");

    std::cout << "Basic idea: " << basic.getIdea(0) << std::endl;
    std::cout << "Copy idea:  " << copy.getIdea(0) << std::endl;

    std::cout << "\n=== Assignment operator test ===" << std::endl;
    Dog a;
    Dog b;

    a.setIdea(0, "Idea A");
    b = a;

    b.setIdea(0, "Idea B");

    std::cout << "A idea: " << a.getIdea(0) << std::endl;
    std::cout << "B idea: " << b.getIdea(0) << std::endl;

    return 0;
}
