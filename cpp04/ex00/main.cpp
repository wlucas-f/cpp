#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(){
    Animal Horse;
    Dog Dog1("Dog");
    Dog1.makeSound();
    std::cout << Horse.getType();
    Animal Cat1("Cat");
    Cat1.makeSound();
}