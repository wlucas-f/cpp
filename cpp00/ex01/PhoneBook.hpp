#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	public:
		PhoneBook();
        void addContact(Contact ctt);
		int getIndex();
		void setIndex(int num);
		Contact getContact(int index);
	private:
		Contact list[8];
		int index;
};

#endif
