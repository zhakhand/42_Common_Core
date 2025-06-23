#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <unistd.h>

int main() {
	{
		std::cout << "\n********* Presidential Pardon Test ***********\n";
		PresidentialPardonForm pForm = PresidentialPardonForm("Huge Ackman");
		std::cout << pForm;
		Bureaucrat dave = Bureaucrat("Dave", 25);
		std::cout << "\n******* Pardon NoSign Test ********\n";
		try {
			dave.executeForm(pForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
		std::cout << "\n******* Pardon NoExec Test ********\n";
		try {
			dave.signForm(pForm);
			dave.executeForm(pForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
		std::cout << "\n******* Pardon OK Test ********\n";
		try {
			for (int i = 0; i < 20; ++i) dave.increaseGrade();
			dave.signForm(pForm);
			dave.executeForm(pForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
	}
	{
		std::cout << "\n********* ShrubberyCreation Test ***********\n";
		ShrubberyCreationForm sForm = ShrubberyCreationForm("Backyard");
		Bureaucrat jack = Bureaucrat("Jack", 145);
		std::cout << "\n******* Shrubbery NoSign Test ********\n";
		try {
			jack.executeForm(sForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
		std::cout << "\n******* Shrubbery NoExec Test ********\n";
		try {
			jack.signForm(sForm);
			jack.executeForm(sForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
		std::cout << "\n******* Shrubbery OK Test ********\n";
		try {
			for (int i = 0; i < 8; ++i) jack.increaseGrade();
			jack.signForm(sForm);
			jack.executeForm(sForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
	}
	{
		std::cout << "\n********* RobotomyRequest Test ***********\n";
		RobotomyRequestForm rForm = RobotomyRequestForm("Anita Mann");
		Bureaucrat rudy = Bureaucrat("Rudy", 72);
		std::cout << "\n******* Robotomy NoSign Test ********\n";
		try {
			rudy.executeForm(rForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
		std::cout << "\n******* Robotomy NoExec Test ********\n";
		try {
			rudy.signForm(rForm);
			rudy.executeForm(rForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
		std::cout << "\n******* Robotomy OK Test ********\n";
		try {
			for (int i = 0; i < 27; ++i) rudy.increaseGrade();
			rudy.signForm(rForm);
			rudy.executeForm(rForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(1);
	}
	return 0;
}