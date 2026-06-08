#include <iostream>
#include "AAnimal.hpp"   // or "Animal.hpp" if you kept the original name
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

static void separator(const std::string &title)
{
    std::cout << "\n══════════════════════════════════════════\n";
    std::cout << "  " << title << "\n";
    std::cout << "══════════════════════════════════════════\n";
}

int main(void)
{
    // ── 1. AAnimal cannot be instantiated ────────────────────────────────────
    // The lines below must NOT compile.  Leave them commented so graders can
    // quickly un-comment to verify the compiler rejects them.
    separator("1. AAnimal is abstract (compile-time check)");
    {
        // AAnimal a;            // ERROR: cannot instantiate abstract class
        // AAnimal *p = new AAnimal(); // ERROR: same
        std::cout << "  (Un-comment the lines in the source to verify "
                     "the compiler rejects them.)\n";
        std::cout << "  If this executable compiled, AAnimal is correctly abstract.\n";
    }

    // ── 2. Dog and Cat still instantiate fine ────────────────────────────────
    separator("2. Dog and Cat still work through AAnimal*");
    {
        AAnimal *d = new Dog();
        AAnimal *c = new Cat();

        std::cout << "Dog type : " << d->getType() << std::endl;
        std::cout << "Cat type : " << c->getType() << std::endl;

        d->makeSound();
        c->makeSound();

        delete d;
        delete c;
    }

    // ── 3. Half-Dog / half-Cat array (same as ex01) ──────────────────────────
    separator("3. Array of 8 Animals via AAnimal*");
    {
        const int SIZE = 8;
        AAnimal *zoo[SIZE];

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

    // ── 4. Deep copy still works ─────────────────────────────────────────────
    separator("4. Deep copy Dog (via AAnimal)");
    {
        Dog d1;
        d1.getBrain()->setIdea(0, "abstract idea");

        Dog d2(d1);
        d1.getBrain()->setIdea(0, "changed");

        std::cout << "  d1 idea[0] : " << d1.getBrain()->getIdea(0) << std::endl;
        std::cout << "  d2 idea[0] : " << d2.getBrain()->getIdea(0) << std::endl;
        std::cout << "  Deep copy  -> "
                  << (d1.getBrain() != d2.getBrain() ? "PASS" : "FAIL")
                  << std::endl;
    }

    // ── 5. Stack objects – destructor order ──────────────────────────────────
    separator("5. Stack objects (destructor order)");
    {
        Dog d;
        Cat c;
        d.makeSound();
        c.makeSound();
    } // ~Cat, ~Dog, then ~AAnimal must fire in correct order

    // ── 6. Type values ────────────────────────────────────────────────────────
    separator("6. Type field values");
    {
        Dog d;
        Cat c;
        std::cout << "Dog::getType() == \"Dog\" -> "
                  << (d.getType() == "Dog" ? "PASS" : "FAIL") << std::endl;
        std::cout << "Cat::getType() == \"Cat\" -> "
                  << (c.getType() == "Cat" ? "PASS" : "FAIL") << std::endl;
    }

    separator("All ex02 tests done");
    return 0;
}
