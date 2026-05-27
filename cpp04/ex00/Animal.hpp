#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        void setType(const std::string &t);
        std::string getType() const;
        void makeSound();
        ~Animal();

    protected:
        std::string type;
        int num;
};

#endif