#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook{
	public:

		PhoneBook();
        void add_contact(Contact);
        //void search_contact();	
		//void exit_pb();	
	private:
		Contact list[8];
		int index;
};

#endif
