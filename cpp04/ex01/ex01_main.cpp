#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

static void separator(const std::string &title)
{
    std::cout << "\n══════════════════════════════════════════\n";
    std::cout << "  " << title << "\n";
    std::cout << "══════════════════════════════════════════\n";
}

// ─── main ───────────────────────────────────────────────────────────────────

int main(void)
{
    // ── 1. Subject sample: new/delete via Animal* ────────────────────────────
    separator("1. Subject sample (no leak)");
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        // Virtual destructor must be in Animal, otherwise UB / leak
        delete j; // should call ~Dog -> ~Brain -> ~Animal
        delete i; // should call ~Cat -> ~Brain -> ~Animal
    }

    // ── 2. Half Dog / half Cat array ─────────────────────────────────────────
    separator("2. Array of 10 Animals (5 Dogs + 5 Cats)");
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
        {
            std::cout << zoo[i]->getType() << " [" << i << "]: ";
            zoo[i]->makeSound();
        }

        std::cout << "\n-- Deleting animals (check destructor order):\n";
        for (int i = 0; i < SIZE; ++i)
            delete zoo[i]; // ~Dog/~Cat must call ~Brain
    }

    // ── 3. Brain ideas – write & read back ───────────────────────────────────
    separator("3. Brain ideas read/write");
    {
        Dog d;

        d.getBrain()->setIdea(0, "chase the mailman");
        d.getBrain()->setIdea(1, "eat everything");
        d.getBrain()->setIdea(99, "sleep all day");

        std::cout << "idea[0]  : " << d.getBrain()->getIdea(0)  << std::endl;
        std::cout << "idea[1]  : " << d.getBrain()->getIdea(1)  << std::endl;
        std::cout << "idea[99] : " << d.getBrain()->getIdea(99) << std::endl;
    }

    // ── 4. Deep copy – Dog ───────────────────────────────────────────────────
    separator("4. Deep copy Dog");
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
        std::cout << "  Brain ptrs differ (deep copy) -> "
                  << (isDeep ? "PASS" : "FAIL") << std::endl;
        std::cout << "  copy value preserved           -> "
                  << (copy.getBrain()->getIdea(0) == "original idea"
                      ? "PASS" : "FAIL") << std::endl;
    }

    // ── 5. Deep copy – Cat ───────────────────────────────────────────────────
    separator("5. Deep copy Cat");
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
        std::cout << "  Brain ptrs differ (deep copy) -> "
                  << (isDeep ? "PASS" : "FAIL") << std::endl;
        std::cout << "  copy value preserved           -> "
                  << (copy.getBrain()->getIdea(0) == "original cat idea"
                      ? "PASS" : "FAIL") << std::endl;
    }

    // ── 6. Brain copy constructor & assignment ───────────────────────────────
    separator("6. Brain copy constructor & assignment");
    {
        Brain b1;
        b1.setIdea(0, "b1 idea 0");
        b1.setIdea(42, "b1 idea 42");

        Brain b2(b1);
        b1.setIdea(0, "b1 modified");

        std::cout << "  b1 idea[0]  : " << b1.getIdea(0)  << std::endl;
        std::cout << "  b2 idea[0]  : " << b2.getIdea(0)  << std::endl;
        std::cout << "  b2 idea[42] : " << b2.getIdea(42) << std::endl;

        Brain b3;
        b3 = b1;
        b1.setIdea(0, "b1 modified again");

        std::cout << "  b1 idea[0] after second modify : "
                  << b1.getIdea(0) << std::endl;
        std::cout << "  b3 idea[0] (should be 'b1 modified') : "
                  << b3.getIdea(0) << std::endl;
    }

    // ── 7. Self-assignment safety ────────────────────────────────────────────
    separator("7. Self-assignment Dog");
    {
        Dog d;
        d.getBrain()->setIdea(0, "self idea");
        d = d; // must not crash or corrupt
        std::cout << "  After self-assign, idea[0]: "
                  << d.getBrain()->getIdea(0) << std::endl;
    }

    // ── 8. Polymorphism still works ──────────────────────────────────────────
    separator("8. Polymorphism (sounds) still works");
    {
        Animal *a = new Dog();
        Animal *b = new Cat();
        a->makeSound();
        b->makeSound();
        delete a;
        delete b;
    }

    separator("All ex01 tests done");
    return 0;
}
