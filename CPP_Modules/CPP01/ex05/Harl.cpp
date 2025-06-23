#include "Harl.hpp"

Harl::Harl() {
	pointer[0] = &Harl::debug;
	pointer[1] = &Harl::info;
	pointer[2] = &Harl::warning;
	pointer[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "What Is Better - To Be Born Good, Or To Overcome Your Evil Nature Through Great Effort?\n";
}

void Harl::info() {
	std::cout << "And he says to the man, \"That's not a horker! That's my wife!\"\n";
}

void Harl::warning() {
	std::cout << "Skyrim Belongs To The Nords!\n";
}

void Harl::error() {
	std::cout << "I Used To Be An Adventurer Like You, Then I Took An Arrow In The Knee\n";
}

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (level != levels[i] && i != 4) ++i;
	switch (i) {
		case 4:
			std::cout << "Ahh, you are awake\n";
			break;
		default:
			(this->*pointer[i])();
	}
}