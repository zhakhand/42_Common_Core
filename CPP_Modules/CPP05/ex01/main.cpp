#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "******* Exception HIGH ********\n";
	try {
		Form("15231", 0, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "******* Exception LOW *********\n";
	try {
		Form("15231", 151, 151);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "******* Signing Exception ********\n";
	try {
		Bureaucrat dave = Bureaucrat("Dave", 42);
		std::cout << dave;
		Form form = Form("4242", 41, 41);
		std::cout << form;
		dave.signForm(form);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "************ OK *************\n";
	try {
		Bureaucrat dave = Bureaucrat("Dave", 41);
		std::cout << dave;
		Form form = Form("4242", 41, 41);
		std::cout << form;
		dave.signForm(form);
		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}