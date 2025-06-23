#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this == &other) return *this;
	AForm::operator=(other);
	this->_target = other.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!this->getSigned())
		throw FormUnsignedException("Form is not signed!\n");
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException("Form requires higher grade to execute!\n");
	system("aplay /home/dzhakhan/Downloads/pardon.wav > /dev/null 2>&1");
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}
