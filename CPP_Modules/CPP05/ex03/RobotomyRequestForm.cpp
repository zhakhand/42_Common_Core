#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("none") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this == &other) return *this;
	AForm::operator=(other);
	this->_target = other.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->getSigned())
		throw FormUnsignedException("Form is not signed!\n");
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException("Form requires higher grade to execute!\n");
	std::cout << "Drilling noises...\n";
	system("aplay /home/dzhakhan/Downloads/drill.wav > /dev/null 2>&1");
	//sleep(2);
	std::srand(static_cast<unsigned int>(std::time(0)));
	int chance = std::rand() % 2;
	std::cout << (chance ? this->getTarget() + " has been successfully Robotomized!\n" 
						: "Robotomy attempt failed!\n");
}