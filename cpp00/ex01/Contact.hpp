#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact{
	public:
		Contact();
		Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string secret);
		std::string getName();
		std::string getSurname();
		std::string getNick();
		std::string getPhone();
		std::string getSecret();
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
