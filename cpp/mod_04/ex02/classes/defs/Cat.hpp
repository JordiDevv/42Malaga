#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal
{
    private:
        Brain* brain;

    public:
        Cat();
        Cat(const Cat& ref);
        Cat& operator=(const Cat& ref);
        ~Cat();
    
        const std::string getType() const;

        const std::string getIdea(const int& i) const;
        void setIdea(const int& i, const std::string& idea);

        void makeSound() const;
};

#endif
