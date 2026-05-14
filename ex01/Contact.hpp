#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>



class Contact{
	public:
	 	Contact(){
			first_name = "unknown";
			last_name = "unknown";
			nickname = "unknown";
			phone_number = "unknown";
			darkest_secret = "unknown";
		};

		Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string secret)
			: first_name(f_name), last_name(l_name), nickname(n_name), phone_number(p_number), darkest_secret(secret) {}

		void print_info(){
			std::cout << "First name: " << first_name << std::endl;
			std::cout << "Last name " << last_name << std::endl;
			std::cout << "Nickname: " << nickname << std::endl;
			std::cout << "Phone number: " << phone_number << std::endl;
			std::cout << "Darkest secret: " << darkest_secret << std::endl;
		}

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
