#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    std::cout << "Array of 8 Animals via Animal*\n\n";
    {
        const int SIZE = 8;
        Animal *zoo[SIZE];

        for (int i = 0; i < SIZE / 2; ++i)
            zoo[i] = new Dog();
        for (int i = SIZE / 2; i < SIZE; ++i)
            zoo[i] = new Cat();

        std::cout << "-- Sounds:\n";
        for (int i = 0; i < SIZE; ++i)
        {
            std::cout << zoo[i]->getType() << ": ";
            zoo[i]->makeSound();
        }

        std::cout << "-- Deleting:\n";
        for (int i = 0; i < SIZE; ++i)
            delete zoo[i];
    }
    std::cout << "\n\n\n";

    std::cout << "Deep copy Dog (via Animal)\n\n";
    {
        Dog d1;
        d1.getBrain()->setIdea(0, "abstract idea");

        Dog d2(d1);
        d1.getBrain()->setIdea(0, "changed");

        bool isDeep = (d1.getBrain() != d2.getBrain());

        std::cout << "  d1 idea[0] : " << d1.getBrain()->getIdea(0) << std::endl;
        std::cout << "  d2 idea[0] : " << d2.getBrain()->getIdea(0) << std::endl;
        std::cout << "  Deep copy  -> " << isDeep << std::endl;
    }
    std::cout << "\n\n\n";
}
