#include "Contact.hpp"
#include <string>

Contact::Contact(){}

Contact::Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret)
	:firstName(fName), lastName(lName), nickName(nName), phoneNumber(pNumber), darkestSecret(dSecret){};

Contact::~Contact(){}

void Contact::list(std::ostream &o){
	o << "\nFirst Name: " << this->firstName;
	o << "\nLast Name: " << this->lastName;
	o << "\nNickname: " << this->nickName;
	o << "\nPhone Number: " << this->phoneNumber;
	o << "\nDarkest Secret: " << this->darkestSecret;
}

static void putspaces(const std::string str, std::ostream &o){
	if (str.length() >= 9)
		return;
	else{
		int len = 10 - str.length();
		while (len--)
			o << " ";
	}
}

void Contact::display(std::ostream &o) {
	putspaces(this->firstName, o);
	o << this->firstName.substr(0, 9) << ((this->firstName.length() >= 9) ? ".|" : "|");
	putspaces(this->lastName, o);
	o << this->lastName.substr(0, 9) << ((this->lastName.length() >= 9) ? ".|" : "|");
	putspaces(this->nickName, o);
	o << this->nickName.substr(0, 9) << ((this->nickName.length() >= 9) ? ".\n" : "\n");
}

const std::string Contact::getNumber() {
	return this->phoneNumber;
}