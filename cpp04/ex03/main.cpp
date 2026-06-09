#include <iostream>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
    std::cout << "Subject sample\n\n";
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");

        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter *bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }
    std::cout << "\n\n\n";

    std::cout << "Ice and Cure getType()\n\n";
    {
        Ice  ice;
        Cure cure;
        std::cout << "Ice  type: " << ice.getType() << std::endl;
        std::cout << "Cure type: " << cure.getType() << std::endl;
    }
    std::cout << "\n\n\n";

    std::cout << "clone() returns same type\n\n";
    {
        Ice  *ice  = new Ice();
        Cure *cure = new Cure();

        AMateria *iceClone  = ice->clone();
        AMateria *cureClone = cure->clone();

        std::cout << "Ice  clone type: " << iceClone->getType() << std::endl;
        std::cout << "Cure clone type: " << cureClone->getType() << std::endl;

        bool isDiff = (iceClone != ice);
        std::cout << "Ice  clone != original ptr -> " << isDiff << std::endl;
        isDiff = (cureClone != cure);
        std::cout << "Cure clone != original ptr -> " << isDiff << std::endl;

        delete ice;
        delete cure;
        delete iceClone;
        delete cureClone;
    }
    std::cout << "\n\n\n";

    std::cout << "Character inventory (4 slots)\n\n";
    {
        Character hero("hero");
        ICharacter *dummy = new Character("dummy");

        AMateria *m0 = new Ice();
        AMateria *m1 = new Cure();
        AMateria *m2 = new Ice();
        AMateria *m3 = new Cure();
        AMateria *m4 = new Ice();

        hero.equip(m0);
        hero.equip(m1);
        hero.equip(m2);
        hero.equip(m3);
        hero.equip(m4);

        std::cout << "-- Using all 4 slots:\n";
        hero.use(0, *dummy);
        hero.use(1, *dummy);
        hero.use(2, *dummy);
        hero.use(3, *dummy);

        delete m4;
        delete dummy;
    }
    std::cout << "\n\n\n";

    std::cout << "Out-of-range use() and unequip() are silent\n\n";
    {
        Character c("test");
        ICharacter *target = new Character("target");

        c.use(0, *target);
        c.use(-1, *target);
        c.use(4, *target);
        c.unequip(0);
        c.unequip(-1);
        c.unequip(99);

        std::cout << "  No crash on invalid indices\n";
        delete target;
    }
    std::cout << "\n\n\n";

    std::cout << "unequip() does not delete Materia\n\n";
    {
        Character c("keeper");
        AMateria *ice = new Ice();
        c.equip(ice);

        c.unequip(0);

        std::cout << "  Materia type after unequip: "
                  << ice->getType() << std::endl;

        delete ice;
    }
    std::cout << "\n\n\n";

    std::cout << "MateriaSource full (4 slots)\n\n";
    {
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        // 5th – silently ignored (no crash)
        src.learnMateria(new Ice());

        AMateria *m = src.createMateria("ice");
        std::cout << "  createMateria(\"ice\") -> " << m->getType() << std::endl;
        delete m;
    }
    std::cout << "\n\n\n";

    std::cout << "Character deep copy (copy constructor)\n\n";
    {
        Character *orig = new Character("original");
        AMateria *ice  = new Ice();
        orig->equip(ice);

        Character copy(*orig);

        std::cout << "  orig name: " << orig->getName() << std::endl;
        std::cout << "  copy name: " << copy.getName()  << std::endl;

        delete orig;

        ICharacter *target = new Character("target");
        copy.use(0, *target);
        delete target;
    }
    std::cout << "\n\n\n";

    std::cout << "Character deep copy (assignment operator)\n\n";
    {
        Character a("alpha");
        Character b("beta");

        AMateria *cure = new Cure();
        a.equip(cure);

        b = a;

        ICharacter *target = new Character("tgt");
        std::cout << "  a uses slot 0: "; a.use(0, *target);
        std::cout << "  b uses slot 0: "; b.use(0, *target);

        delete target;
    }
    std::cout << "\n\n\n";

    std::cout << "Full workflow with multiple characters\n\n";
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *alice = new Character("Alice");
        ICharacter *bob   = new Character("Bob");

        alice->equip(src->createMateria("ice"));
        alice->equip(src->createMateria("cure"));

        bob->equip(src->createMateria("ice"));
        bob->equip(src->createMateria("ice"));

        alice->use(0, *bob);
        alice->use(1, *bob);
        bob->use(0, *alice);
        bob->use(1, *alice);

        delete alice;
        delete bob;
        delete src;
    }
    std::cout << "\n\n\n";
}
