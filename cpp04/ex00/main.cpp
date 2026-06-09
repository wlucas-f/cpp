#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "Subject sample\n\n";
    {
        const Animal *meta = new Animal();
        const Animal *j    = new Dog();
        const Animal *i    = new Cat();

        std::cout << "Dog type : " << j->getType() << std::endl;
        std::cout << "Cat type : " << i->getType() << std::endl;

        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    std::cout << "\n\n\n";

    std::cout << "Type field values\n\n";
    {
        Dog d;
        Cat c;
        Animal a;

        std::cout << d.getType() << std::endl;
        std::cout << c.getType() << std::endl;
        std::cout << a.getType() << std::endl;
    }
    std::cout << "\n\n\n";

    std::cout << "Stack-allocated objects\n\n";
    {
        Dog  d;
        Cat  c;
        Animal a;

        d.makeSound();
        c.makeSound();
        a.makeSound();
    }
    std::cout << "\n\n\n";

    std::cout << "Virtual dispatch through Animal*\n\n";
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
    std::cout << "\n\n\n";

    std::cout << "Copy constructor & assignment\n\n";
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
    std::cout << "\n\n\n";

    std::cout << "WrongAnimal / WrongCat (no virtual)\n\n";
    {
        const WrongAnimal *wa = new WrongAnimal();
        const WrongAnimal *wc = new WrongCat();

        std::cout << "WrongAnimal type : " << wa->getType() << std::endl;
        std::cout << "WrongCat type    : " << wc->getType() << std::endl;

        std::cout << "wa->makeSound() -> ";
        wa->makeSound();
        std::cout << "wc->makeSound() -> ";
        wc->makeSound();

        delete wa;
        delete wc;
    }
    std::cout << "\n\n\n";

    std::cout << "WrongCat as WrongCat*\n\n";
    {
        const WrongCat *wc = new WrongCat();
        std::cout << "wc->makeSound() directly -> ";
        wc->makeSound(); // called on WrongCat*, so WrongCat's own function
        delete wc;
    }
    std::cout << "\n\n\n";

    std::cout << "Confirm Dog != Cat != Animal sounds\n\n";
    {
        Animal  a;
        Dog     d;
        Cat     c;

        std::cout << "Animal: "; a.makeSound();
        std::cout << "Dog:    "; d.makeSound();
        std::cout << "Cat:    "; c.makeSound();
    }
}
