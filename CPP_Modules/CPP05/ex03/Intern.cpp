#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cctype>

Intern::Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string lName = to_lower(formName);
	int form = 0;
	while (lName != forms[form] && form != 3) form++;
	system("aplay /home/dzhakhan/Downloads/printer.wav > /dev/null 2>&1");
	switch (form) {
		case (0):
			std::cout << "Intern creates Shrubbery Creation Form\n";
			return new ShrubberyCreationForm(target);
		case (1):
			std::cout << "Intern creates Robotomy Request Form\n";
			return new RobotomyRequestForm(target);
		case (2):
			std::cout << "Intern creates Presidential Pardon Form\n";
			return new PresidentialPardonForm(target);
		default:
			throw Intern::InvalidFormException("Intern can not find a form " + lName + "\n");
	}
}

Intern::InvalidFormException::InvalidFormException(const std::string& msg) : _message(msg){}

Intern::InvalidFormException::~InvalidFormException() throw() {}

const char* Intern::InvalidFormException::what() const throw() {
	return _message.c_str();
}

std::string to_lower(const std::string& str) {
	std::string res = str;
	for (std::size_t i = 0; i < res.length(); ++i)
		res[i] = std::tolower(static_cast<unsigned char>(res[i]));
	return res;
}