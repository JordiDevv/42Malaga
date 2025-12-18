#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog& ref);
        Dog& operator=(const Dog& ref);
        ~Dog();

        const std::string getType() const;

        const std::string getIdea(const int& i) const;
        void setIdea(const int& i, const std::string& idea);
        
        void makeSound() const;
};

#endif
