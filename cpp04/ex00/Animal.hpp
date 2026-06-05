#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    public:
        Animal(const std::string &type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        void setType(const std::string &type);
        std::string getType() const;
        virtual void makeSound() const;
        virtual ~Animal();

    protected:
        std::string type;
        int num;
};

#endif
