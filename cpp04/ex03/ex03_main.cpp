#include <iostream>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

static void separator(const std::string &title)
{
    std::cout << "\n══════════════════════════════════════════\n";
    std::cout << "  " << title << "\n";
    std::cout << "══════════════════════════════════════════\n";
}

// ─── main ───────────────────────────────────────────────────────────────────

int main(void)
{
    // ── 1. Subject sample (must match expected output exactly) ───────────────
    separator("1. Subject sample");
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

        me->use(0, *bob); // * shoots an ice bolt at bob *
        me->use(1, *bob); // * heals bob's wounds *

        delete bob;
        delete me;
        delete src;
    }

    // ── 2. Ice and Cure types ─────────────────────────────────────────────────
    separator("2. Ice and Cure getType()");
    {
        Ice  ice;
        Cure cure;
        std::cout << "Ice  type: " << ice.getType() << std::endl;
        std::cout << "Cure type: " << cure.getType() << std::endl;
    }

    // ── 3. clone() returns correct type ──────────────────────────────────────
    separator("3. clone() returns same type");
    {
        Ice  *ice  = new Ice();
        Cure *cure = new Cure();

        AMateria *iceClone  = ice->clone();
        AMateria *cureClone = cure->clone();

        std::cout << "Ice  clone type: " << iceClone->getType() << std::endl;
        std::cout << "Cure clone type: " << cureClone->getType() << std::endl;

        // Clone must be a different object
        std::cout << "Ice  clone != original ptr -> "
                  << (iceClone  != ice  ? "PASS" : "FAIL") << std::endl;
        std::cout << "Cure clone != original ptr -> "
                  << (cureClone != cure ? "PASS" : "FAIL") << std::endl;

        delete ice;
        delete cure;
        delete iceClone;
        delete cureClone;
    }

    // ── 4. Character inventory: equip up to 4 slots ──────────────────────────
    separator("4. Character inventory (4 slots)");
    {
        Character hero("hero");
        ICharacter *dummy = new Character("dummy");

        AMateria *m0 = new Ice();
        AMateria *m1 = new Cure();
        AMateria *m2 = new Ice();
        AMateria *m3 = new Cure();
        AMateria *m4 = new Ice(); // 5th – must be silently ignored

        hero.equip(m0);
        hero.equip(m1);
        hero.equip(m2);
        hero.equip(m3);
        hero.equip(m4); // inventory full – nothing should happen (no crash)

        std::cout << "-- Using all 4 slots:\n";
        hero.use(0, *dummy);
        hero.use(1, *dummy);
        hero.use(2, *dummy);
        hero.use(3, *dummy);

        // m4 was never equipped, must be deleted manually
        delete m4;
        delete dummy;
        // hero destructor deletes m0-m3
    }

    // ── 5. use() / unequip() on invalid index – no crash ────────────────────
    separator("5. Out-of-range use() and unequip() are silent");
    {
        Character c("test");
        ICharacter *target = new Character("target");

        c.use(0, *target);    // empty slot – nothing
        c.use(-1, *target);   // invalid index – nothing
        c.use(4, *target);    // out of range – nothing
        c.unequip(0);         // nothing equipped – nothing
        c.unequip(-1);        // invalid – nothing
        c.unequip(99);        // out of range – nothing

        std::cout << "  No crash on invalid indices\n";
        delete target;
    }

    // ── 6. unequip() does NOT delete the Materia ─────────────────────────────
    separator("6. unequip() does not delete Materia");
    {
        Character c("keeper");
        AMateria *ice = new Ice();
        c.equip(ice);

        c.unequip(0);

        std::cout << "  Materia type after unequip: "
                  << ice->getType() << std::endl;
        std::cout << "  unequip() did not delete\n";

        delete ice;
    }

    // ── 7. MateriaSource: unknown type returns 0 ─────────────────────────────
    separator("7. createMateria() with unknown type returns 0");
    {
        MateriaSource src;
        src.learnMateria(new Ice());

        AMateria *m = src.createMateria("fire");
        std::cout << "  createMateria(\"fire\") == 0 -> "
                  << (m == 0 ? "PASS" : "FAIL") << std::endl;
        // no delete needed – it's null
    }

    // ── 8. MateriaSource: learn up to 4 templates ────────────────────────────
    separator("8. MateriaSource full (4 slots)");
    {
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        // 5th – silently ignored (no crash)
        src.learnMateria(new Ice());

        AMateria *m = src.createMateria("ice");
        std::cout << "  createMateria(\"ice\") -> "
                  << (m ? m->getType() : "null") << std::endl;
        delete m;
    }

    // ── 9. Character deep copy – constructor ─────────────────────────────────
    separator("9. Character deep copy (copy constructor)");
    {
        Character *orig = new Character("original");
        AMateria *ice  = new Ice();
        orig->equip(ice);

        Character copy(*orig);

        std::cout << "  orig name: " << orig->getName() << std::endl;
        std::cout << "  copy name: " << copy.getName()  << std::endl;

        // Deleting original must not affect copy
        delete orig; // orig's inventory freed; copy owns its own clones

        ICharacter *target = new Character("target");
        copy.use(0, *target); // must still work – PASS if no crash/UB
        delete target;
    }

    // ── 10. Character deep copy – assignment ─────────────────────────────────
    separator("10. Character deep copy (assignment operator)");
    {
        Character a("alpha");
        Character b("beta");

        AMateria *cure = new Cure();
        a.equip(cure);

        b = a; // deep copy: b gets its own clone of cure

        ICharacter *target = new Character("tgt");
        std::cout << "  a uses slot 0: "; a.use(0, *target);
        std::cout << "  b uses slot 0: "; b.use(0, *target);

        delete target;
        // a and b destructors each clean their own inventory
    }

    // ── 11. Character self-assignment safety ─────────────────────────────────
    separator("11. Character self-assignment");
    {
        Character c("selfie");
        AMateria *ice = new Ice();
        c.equip(ice);
        c = c; // must not double-free or corrupt

        ICharacter *target = new Character("t");
        c.use(0, *target);
        delete target;
        std::cout << "  Self-assignment safe\n";
    }

    // ── 12. Full workflow: src -> equip -> use -> delete ─────────────────────
    separator("12. Full workflow with multiple characters");
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *alice = new Character("Alice");
        ICharacter *bob   = new Character("Bob");

        // Alice equips Ice and Cure
        alice->equip(src->createMateria("ice"));
        alice->equip(src->createMateria("cure"));

        // Bob equips two Ice
        bob->equip(src->createMateria("ice"));
        bob->equip(src->createMateria("ice"));

        alice->use(0, *bob);    // Alice shoots ice at Bob
        alice->use(1, *bob);    // Alice heals Bob
        bob->use(0, *alice);    // Bob shoots ice at Alice
        bob->use(1, *alice);    // Bob shoots ice at Alice again

        delete alice;
        delete bob;
        delete src;
    }

    return 0;
}
