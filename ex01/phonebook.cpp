#include "phonebook.hpp"

PhoneBook::PhoneBook():index(0){}

void PhoneBook::add_contact(Contact c)
{
    list[index++] = c;
}
