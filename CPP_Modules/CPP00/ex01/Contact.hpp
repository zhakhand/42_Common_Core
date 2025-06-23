#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret);
	~Contact();

	void list(std::ostream &o);
	void display(std::ostream &o);
	const std::string getNumber();
};

#endif