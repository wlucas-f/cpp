#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        void setIdea(const std::string &idea, int index);
        std::string getIdea(int index);
        ~Brain();

    protected:
        std::string ideas[100];
};

#endif