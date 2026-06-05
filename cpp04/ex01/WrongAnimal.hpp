#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    public:
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
        void setType(const std::string &type);
        std::string getType() const;
        virtual void makeSound();
        virtual ~WrongAnimal();

    protected:
        std::string type;
        int num;
};

#endif
