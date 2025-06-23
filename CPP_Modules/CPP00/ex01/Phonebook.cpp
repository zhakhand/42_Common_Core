#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook(){
	this->currIndex = 0;
	this->maxSize = 8;
}

PhoneBook::~PhoneBook(){}

static bool containsNonPrintable(const std::string str){
	for (size_t i = 0; i < str.length(); ++i){
		if (str.at(i) < 32 || str.at(i) > 126) return true;
	}
	return false;
}

static std::string getInfo(const std::string info){
	std::string str;
	while (1){
		try{
			std::cout << info;
			if (!std::getline(std::cin, str))
				throw std::logic_error("NULL INPUT!!!");
			if (str.empty())
				throw std::invalid_argument("Field can not be empty!");
			if (containsNonPrintable(str))
				throw std::invalid_argument("Field contains invalid characters!");
			break;
		}catch (const std::invalid_argument& e){
			std::cerr << e.what() << '\n';
			continue;
		}
	}
	return str;
}

static bool hasLetters(const std::string number){
	for (size_t i = 0; i < number.length(); ++i){
		if (!isdigit(number.at(i))) return (1);
	}
	return 0;
}

static std::string getNumber(){
	std::string number;
	while (!false) {
		try{
			std::cout << "\nPhone Number: ";
			if (!std::getline(std::cin, number))
				throw std::logic_error("NULL INPUT!!!");
			if (number.empty())
				throw std::invalid_argument("Field can not be empty!");
			if (containsNonPrintable(number) || hasLetters(number))
				throw std::invalid_argument("Field contains invalid characters!");
			break;
		}catch (const std::invalid_argument& e){
			std::cerr << e.what() << '\n';
		}
	}
	return number;
}

void PhoneBook::addContact(){
	std::cout << "\nPlease Enter Contact Info:\n";
	std::string fName = getInfo("\nFirst Name: ");
	std::string lName = getInfo("\nLast Name: ");
	std::string nName = getInfo("\nNickName: ");
	std::string pNumber = getNumber();
	std::string dSecret = getInfo("\nDarkest Secret: ");
	this->contacts[this->currIndex] = Contact(fName, lName, nName, pNumber, dSecret);
	this->currIndex = (this->currIndex + 1) % this->maxSize;
}


void PhoneBook::search() {
	int	idx = 0;
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME\n";
	for (size_t i = 0; i < this->maxSize; ++i){
		if (contacts[i].getNumber().empty())
			continue ;
		std::cout << "         " << idx++ << "|";
		contacts[i].display(std::cout);
	}
	std::string index;
	while (!false) {
		try{
			std::cout << "\nChoose an index of the Contact [0-7]: ";
			if (!std::getline(std::cin, index))
				throw std::logic_error("NULL INPUT!!!");
			if (index.empty() || index.length() > 1 || containsNonPrintable(index) || hasLetters(index))
				throw std::invalid_argument("Please provide a single digit argument between 0 and 7!");
			if (index.at(0) - '0' > 7 || index.at(0) - '0' < 0)
				throw std::invalid_argument("Index out of range!");
			if (contacts[index.at(0) - '0'].getNumber().empty())
				throw std::invalid_argument("Provide index of an existing contact!");
			else
				break;
		}catch (const std::invalid_argument& e){
			std::cerr << e.what() << '\n';
			continue;
		}
	}
	this->contacts[index.at(0) - '0'].list(std::cout);
}