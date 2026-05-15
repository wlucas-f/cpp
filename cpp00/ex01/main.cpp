#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>

void clearScreen(){
    std::cout << "\033[2J\033[H";
}

std::string fmtColumn(const std::string &value){
    if(value.length() > 10)
        return value.substr(0,9) + ".";
    return value;
}
void printRow(const std::string &c1, const std::string &c2,
                const std::string &c3, const std::string &c4){
    std::cout << std::right
                    << std::setw(10) << fmtColumn(c1) << "|"
                    << std::setw(10) << fmtColumn(c2) << "|"
                    << std::setw(10) << fmtColumn(c3) << "|"
                    << std::setw(10) << fmtColumn(c4) << std::endl;
}

void cmdAdd(PhoneBook &pb){
    clearScreen();

    std::cout << "ADD CONTACT" << std::endl << std::endl;

    std::string name, surname, nick, number, secret;

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

    if(name.empty() || surname.empty() || nick.empty() || number.empty() || secret.empty())
    {
        std::cout << std::endl << "Empty fields are not accepted! Press ENTER...";
        std::cout.flush();
        std::cin.ignore();
        std::cin.get();

        clearScreen();
        return ;
    }

    pb.addContact(Contact(name, surname, nick, number, secret));

    std::cout << std::endl << "Contact added! Press ENTER...";
    std::cout.flush();
    std::cin.ignore();
    std::cin.get();

    clearScreen();
}

void cmdSearch(PhoneBook &pb){
    clearScreen();

    if (pb.getIndex() >= 8)
        pb.setIndex(8);
    
    if(pb.getIndex() == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        std::cout << std::endl << "Press ENTER...";
        std::cout.flush();
        std::cin.ignore();
        std::cin.get();
        clearScreen();
        return ;
    }

    std::cout << "[SEARCH]" << std::endl << std:: endl;
    printRow("Index", "First Name", "Last Name", "Nick Name");

    for(int i = 0; i < pb.getIndex(); i++)
    {
        std::stringstream ss;
        ss << i;
        Contact c = pb.getContact(i);
        printRow(ss.str(), c.getName(), c.getSurname(), c.getNick());
    }

    std::cout << std::endl << "Enter index: ";
    std::cout.flush();

    std::string input;
    std::cin >> input;
    if(!std::cin)
        return ;

    std::istringstream iss(input);
    int idx;
    if(!(iss >> idx) || idx < 0 || idx >= pb.getIndex()){
        std::cerr << "Invalid index." << std::endl;
    }
    else {
        Contact c = pb.getContact(idx);
        std::cout << std::endl;
        std::cout << "First Name    :" << c.getName() << std::endl;
        std::cout << "Last Name     :" << c.getSurname() << std::endl;
        std::cout << "Nick Name     :" << c.getNick() << std::endl;
        std::cout << "Phone Number  :" << c.getPhone() << std::endl;
        std::cout << "Darkest Secret:" << c.getSecret() << std::endl;
    }

    std::cout << std::endl << "Press ENTER...";
    std::cout.flush();
    std::cin.ignore();
    std::cin.get();

    clearScreen();
}

int main()
{
    PhoneBook pb;
    std::string option;

    clearScreen();
    std::cout << "PHONEBOOK" << std::endl;
    while(1){
        std::cout << std::endl;
        std::cout << "Choose one of the following options: Add, Search, Exit." << std::endl;
        std::cout << "phonebook> ";
        std::cin >> option;
        if(option == "Add")
            cmdAdd(pb);
        else if(option == "Search")
            cmdSearch(pb);
        else if(option == "Exit")
            return (0);
    }
}
