#include "PhoneBook.hpp"

PhoneBook::PhoneBook():index(0){};

void PhoneBook::addContact(Contact ctt){
    if (index >= 8)
        list[index % 8] = ctt;
    else
        list[index] = ctt;
    index++;
}

int PhoneBook::getIndex(){
    return (index);
}

void PhoneBook::setIndex(int num){
    index = num;
}

Contact PhoneBook::getContact(int index){
    return (list[index]);
}
