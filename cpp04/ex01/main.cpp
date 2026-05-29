#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    std::cout << std::endl;
    Animal *farm[10];
    for(int i = 0; i < 10; i++)
    {
        if (i%2)
            farm[i] = new Dog("Dog");
        else
            farm[i] = new Cat("Cat");
    }
    std::cout << std::endl;
    for(int i = 0; i < 10; i++)
        farm[i]->makeSound();
    std::cout << std::endl;
    for(int i = 0; i < 10; i++)
    	delete farm[i];
    return 0;
}
