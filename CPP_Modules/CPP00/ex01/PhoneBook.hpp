#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook {
private:
	Contact contacts[8];
	size_t	currIndex;
	size_t	maxSize;

public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	search();
};

#endif