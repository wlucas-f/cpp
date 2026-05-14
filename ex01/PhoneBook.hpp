#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	public:
		PhoneBook();
        void addContact(Contact ctt){
			list[index] = ctt;
			index++;
		}
		void search(){
			list[0].print_info();
		}
	private:
		Contact list[8];
		int index;
};

#endif
