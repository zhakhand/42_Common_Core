#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
	: _name("Default"), _signed(false), _gradeSign(150), _gradeExec(150) {}

AForm::AForm(const std::string& name, unsigned int gradeSign, unsigned int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign > 150)
		throw AForm::GradeTooLowException("Grade to sign the form is too low!\n");
	if (gradeSign < 1)
		throw AForm::GradeTooHighException("Grade to sign the form is too high!\n");
	if (gradeExec > 150)
		throw AForm::GradeTooLowException("Grade to execute the form is too low!\n");
	if (gradeExec < 1)
		throw AForm::GradeTooHighException("Grade to execute the form is too high!\n");
}

AForm::AForm(const AForm& other) : _name(other.getName()), _signed(other.getSigned()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec()) {}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other) return *this;
	this->_signed = other.getSigned();
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

unsigned int AForm::getGradeSign() const {
	return this->_gradeSign;
}

unsigned int AForm::getGradeExec() const {
	return this->_gradeExec;
}

#include <cstdlib>
#include <unistd.h>

void AForm::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException("grade required to sign the form is higher!\n");
	this->_signed = true;
	system("aplay /home/dzhakhan/Downloads/stamp.wav > /dev/null 2>&1");
	std::cout << bur.getName() << " signed " << this->getName() << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : _message(msg){}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char* AForm::GradeTooHighException::what() const throw() {
	return _message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : _message(msg){}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char* AForm::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

AForm::FormUnsignedException::FormUnsignedException(const std::string& msg) : _message(msg){}

AForm::FormUnsignedException::~FormUnsignedException() throw() {}

const char* AForm::FormUnsignedException::what() const throw() {
	return _message.c_str();
}

std::ostream& operator<<(std::ostream& o, const AForm& form) {
	o << "Name:             " << form.getName() << "\n"
	  << "Status:           " << (form.getSigned() ? "signed\n" : "not signed\n")
	  << "Grade to sign:    " << form.getGradeSign() << "\n"
	  << "Grade to execute: " << form.getGradeExec() << std::endl;
	return o;
}