#include "PhoneBook.hpp"

int main(){
	std::cout << "\nWelcome to my amazing(not so) Notebook\n";
	PhoneBook book;

	while (!false) {
		try{
			std::cout << "\nEnter 'ADD', 'SEARCH' or 'EXIT': ";
			std::string option;
			if (!getline(std::cin, option))
				throw std::logic_error("\nNULL INPUT!!!");
			if (option.empty())
				continue;
			else if (option == "ADD")
				book.addContact();
			else if (option == "SEARCH")
				book.search();
			else if (option == "EXIT")
				break;
			else
				continue;
		}catch (std::logic_error e){
			std::cerr << e.what() << '\n';
			break;
		}
	}
}