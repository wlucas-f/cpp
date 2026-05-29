#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    public:
        Dog();
        Dog(const std::string &type);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        void makeSound() override;
        ~Dog();

    private:
        Brain* brain;
};

#endif
