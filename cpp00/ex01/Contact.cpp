#include "Contact.hpp"

Contact::Contact(){};

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string secret)
    : first_name(f_name), last_name(l_name), nickname(n_name), phone_number(p_number), darkest_secret(secret) {}
std::string Contact::getName(){
    return(first_name);
}

std::string Contact::getSurname(){
    return(last_name);
}

std::string Contact::getNick(){
    return(nickname);
}

std::string Contact::getPhone(){
    return(phone_number);
}

std::string Contact::getSecret(){
    return(darkest_secret);
}