#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "What Is Better - To Be Born Good, Or To Overcome Your Evil Nature Through Great Effort?\n\n";
}

void Harl::info() {
	std::cout << "And he says to the man, \"That's not a horker! That's my wife!\"\n\n";
}

void Harl::warning() {
	std::cout << "Skyrim Belongs To The Nords!\n\n";
}

void Harl::error() {
	std::cout << "I Used To Be An Adventurer Like You, Then I Took An Arrow In The Knee\n\n";
}

void Harl::complain(std::string level) {
	int i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (level != levels[i] && i != 4) ++i;
	switch (i) {
		case 4:
			std::cout << "[ Ahh, you are awake ]\n";
			break;
		case 0: 
			std::cout << "[ DEBUG ]\n";
			debug();
		case 1:
			std::cout << "[ INFO ]\n";
			info();
		case 2:
			std::cout << "[ WARNING ]\n";
			warning();
		case 3:
			std::cout << "[ ERROR ]\n";
			error();
	}
}