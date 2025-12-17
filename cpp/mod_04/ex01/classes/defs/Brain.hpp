#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(const Brain& ref);
        Brain& operator=(const Brain& ref);
        ~Brain();

        const std::string getIdea(const int& i) const;
        void setIdea(const int& i, const std::string& idea);
};

#endif
