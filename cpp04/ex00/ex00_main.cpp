#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// ─── helpers ────────────────────────────────────────────────────────────────

static void separator(const std::string &title)
{
    std::cout << "\n══════════════════════════════════════════\n";
    std::cout << "  " << title << "\n";
    std::cout << "══════════════════════════════════════════\n";
}

// ─── main ───────────────────────────────────────────────────────────────────

int main(void)
{
    // ── 1. Required sample from the subject ─────────────────────────────────
    separator("1. Subject sample");
    {
        const Animal *meta = new Animal();
        const Animal *j    = new Dog();
        const Animal *i    = new Cat();

        std::cout << "Dog type : " << j->getType() << std::endl;
        std::cout << "Cat type : " << i->getType() << std::endl;

        // Must dispatch to the correct overrides, not Animal::makeSound
        i->makeSound();   // cat sound
        j->makeSound();   // dog sound
        meta->makeSound();// base animal sound

        delete meta;
        delete j;
        delete i;
    }

    // ── 2. type field correctness ────────────────────────────────────────────
    separator("2. Type field values");
    {
        Dog d;
        Cat c;
        Animal a;

        std::cout << "Dog::getType()    == \"Dog\"    -> "
                  << (d.getType() == "Dog"    ? "PASS" : "FAIL") << std::endl;
        std::cout << "Cat::getType()    == \"Cat\"    -> "
                  << (c.getType() == "Cat"    ? "PASS" : "FAIL") << std::endl;
        // Animal type is anything except Dog/Cat (just print it)
        std::cout << "Animal::getType() == \""
                  << a.getType() << "\"" << std::endl;
    }

    // ── 3. Stack objects (no pointers) ───────────────────────────────────────
    separator("3. Stack-allocated objects");
    {
        Dog  d;
        Cat  c;
        Animal a;

        d.makeSound();
        c.makeSound();
        a.makeSound();
    } // destructors fire here

    // ── 4. Virtual dispatch through base pointer (polymorphism core) ─────────
    separator("4. Virtual dispatch through Animal*");
    {
        const Animal *animals[4];
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();

        for (int i = 0; i < 4; ++i)
        {
            std::cout << animals[i]->getType() << " says: ";
            animals[i]->makeSound();
        }

        for (int i = 0; i < 4; ++i)
            delete animals[i];
    }

    // ── 5. Copy semantics ────────────────────────────────────────────────────
    separator("5. Copy constructor & assignment");
    {
        std::cout << "-- Copy constructing Dog:\n";
        Dog d1;
        Dog d2(d1);
        std::cout << "  d1 type: " << d1.getType()
                  << " | d2 type: " << d2.getType() << std::endl;

        std::cout << "-- Assignment Dog:\n";
        Dog d3;
        d3 = d1;
        std::cout << "  d3 type: " << d3.getType() << std::endl;

        std::cout << "-- Copy constructing Cat:\n";
        Cat c1;
        Cat c2(c1);
        std::cout << "  c1 type: " << c1.getType()
                  << " | c2 type: " << c2.getType() << std::endl;
    }

    // ── 6. WrongAnimal / WrongCat – NON-virtual dispatch ────────────────────
    separator("6. WrongAnimal / WrongCat (no virtual)");
    {
        const WrongAnimal *wa = new WrongAnimal();
        const WrongAnimal *wc = new WrongCat();   // WrongCat through WrongAnimal*

        std::cout << "WrongAnimal type : " << wa->getType() << std::endl;
        std::cout << "WrongCat type    : " << wc->getType() << std::endl;

        // Both must call WrongAnimal::makeSound (no virtual override)
        std::cout << "wa->makeSound() -> ";
        wa->makeSound();
        std::cout << "wc->makeSound() -> ";
        wc->makeSound(); // should print WrongAnimal's sound, NOT WrongCat's

        delete wa;
        delete wc;
    }

    // ── 7. WrongCat as itself (should use own sound) ─────────────────────────
    separator("7. WrongCat as WrongCat*");
    {
        const WrongCat *wc = new WrongCat();
        std::cout << "wc->makeSound() directly -> ";
        wc->makeSound(); // called on WrongCat*, so WrongCat's own function
        delete wc;
    }

    // ── 8. Confirm Animal sound is NOT used for Dog/Cat via virtual ──────────
    separator("8. Confirm Dog != Cat != Animal sounds");
    {
        Animal  a;
        Dog     d;
        Cat     c;

        std::cout << "Animal: "; a.makeSound();
        std::cout << "Dog:    "; d.makeSound();
        std::cout << "Cat:    "; c.makeSound();
    }

    separator("All tests done");
    return 0;
}
