#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog(std::string &type);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        void setType(const std::string &t);
        std::string getType() const;
        ~Dog();

    private:
};

#endif