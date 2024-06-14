#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"

class Phonebook {
	private:
		Contacts _contacts[8];

	public:
		bool add_contact(int i);
		void display_contacts();
		bool search_contact();
};

#endif