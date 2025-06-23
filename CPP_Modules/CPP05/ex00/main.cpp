#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat("Dave", 0);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		Bureaucrat("Dave", 151);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		Bureaucrat dave = Bureaucrat("Dave", 1);
		std::cout << dave;
		dave.increaseGrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		Bureaucrat dave = Bureaucrat("Dave", 150);
		std::cout << dave;
		dave.decreaseGrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}