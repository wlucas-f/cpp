#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <climits>

void addOption(PhoneBook &pb){
    std::string name;
    std::string surname;
    std::string nick;
    std::string number;
    std::string secret;

    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Insert name: " << std::endl;
    std::getline(std::cin, name);
    std::cout << "Insert surname: " << std::endl;
    std::getline(std::cin, surname);
    std::cout << "Insert nickname: " << std::endl;
    std::getline(std::cin, nick);
    std::cout << "Insert number: " << std::endl;
    std::getline(std::cin, number);
    std::cout << "Insert secret: " << std::endl;
    std::getline(std::cin, secret);

    pb.addContact(Contact(name, surname, nick, number, secret));
}

int main()
{
    PhoneBook pb;
    std::string option;

    std::cout << "PHONEBOOK" << std::endl;
    while(1){
        std::cout << std::endl;
        std::cout << "Choose one of the following options: Add, Search, Exit." << std::endl;
        std::cout << "phonebook> ";
        std::cin >> option;
        if(option == "Add")
            addOption(pb);
        else if(option == "Search")
            pb.search();
        else if(option == "Exit")
            return (0);
    }
}
