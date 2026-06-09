#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    std::cout << "Subject sample (no leak)\n\n";
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        delete j;
        delete i;
    }
    std::cout << "\n\n\n";

    std::cout << "Array of 10 Animals (5 Dogs + 5 Cats)\n\n";
    {
        const int SIZE = 10;
        Animal *zoo[SIZE];

        std::cout << "-- Creating animals:\n";
        for (int i = 0; i < SIZE / 2; ++i)
            zoo[i] = new Dog();
        for (int i = SIZE / 2; i < SIZE; ++i)
            zoo[i] = new Cat();

        std::cout << "\n-- Making sounds:\n";
        for (int i = 0; i < SIZE; ++i)
            zoo[i]->makeSound();

        std::cout << "\n-- Deleting animals (check destructor order):\n";
        for (int i = 0; i < SIZE; ++i)
            delete zoo[i]; // ~Dog/~Cat must call ~Brain
    }
    std::cout << "\n\n\n";

    std::cout << "Brain ideas read/write\n\n";
    {
        Dog d;

        d.getBrain()->setIdea(0, "chase the mailman");
        d.getBrain()->setIdea(1, "eat everything");
        d.getBrain()->setIdea(99, "sleep all day");

        std::cout << "idea[0]  : " << d.getBrain()->getIdea(0)  << std::endl;
        std::cout << "idea[1]  : " << d.getBrain()->getIdea(1)  << std::endl;
        std::cout << "idea[99] : " << d.getBrain()->getIdea(99) << std::endl;
    }
    std::cout << "\n\n\n";

    std::cout << "Deep copy Dog\n\n";
    {
        Dog original;
        original.getBrain()->setIdea(0, "original idea");

        std::cout << "-- Copy constructor:\n";
        Dog copy(original);

        // Modify original after copy – copy must not change
        original.getBrain()->setIdea(0, "modified original");

        std::cout << "  original idea[0] : "
                  << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "  copy     idea[0] : "
                  << copy.getBrain()->getIdea(0) << std::endl;

        bool isDeep = (original.getBrain() != copy.getBrain());
        std::cout << "  Brain ptrs differ (deep copy) -> " << isDeep << std::endl;
        std::cout << "  copy value preserved           -> " << copy.getBrain()->getIdea(0) << std::endl;
    }
    std::cout << "\n\n\n";

    std::cout << "Deep copy Dog\n\n";
    {
        Cat original;
        original.getBrain()->setIdea(0, "original cat idea");

        std::cout << "-- Assignment operator:\n";
        Cat copy;
        copy = original;

        original.getBrain()->setIdea(0, "modified cat original");

        std::cout << "  original idea[0] : "
                  << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "  copy     idea[0] : "
                  << copy.getBrain()->getIdea(0) << std::endl;

        bool isDeep = (original.getBrain() != copy.getBrain());
        std::cout << "  Brain ptrs differ (deep copy) -> " << isDeep << std::endl;
        std::cout << "  copy value preserved           -> " << copy.getBrain()->getIdea(0) << std::endl;
    }
    std::cout << "\n\n\n";

    std::cout << "Brain copy constructor & assignment\n\n";
    {
        Brain b1;
        b1.setIdea(0, "b1 idea 0");
        b1.setIdea(42, "b1 idea 42");

        Brain b2(b1);
        b1.setIdea(0, "b1 modified");

        std::cout << "  b1 idea[0]  : " << b1.getIdea(0)  << std::endl;
        std::cout << "  b2 idea[0]  : " << b2.getIdea(0)  << std::endl;
        std::cout << "  b2 idea[42] : " << b2.getIdea(42) << std::endl;
    }
    std::cout << "\n\n\n";
}
