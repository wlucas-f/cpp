#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat(const std::string &type);
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);
        ~WrongCat();

    private:
};

#endif
