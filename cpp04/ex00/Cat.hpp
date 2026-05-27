#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat(std::string &type);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        void setType(const std::string &t);
        std::string getType() const;
        ~Cat();

    private:
};

#endif