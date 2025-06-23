#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
	: _name("Default"), _signed(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(const std::string& name, unsigned int gradeSign, unsigned int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign > 150)
		throw Form::GradeTooLowException("Grade to sign the form is too low!\n");
	if (gradeSign < 1)
		throw Form::GradeTooHighException("Grade to sign the form is too high!\n");
	if (gradeExec > 150)
		throw Form::GradeTooLowException("Grade to execute the form is too low!\n");
	if (gradeExec < 1)
		throw Form::GradeTooHighException("Grade to execute the form is too high!\n");
}

Form::Form(const Form& other) : _name(other.getName()), _signed(other.getSigned()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec()) {}

Form& Form::operator=(const Form& other) {
	if (this == &other) return *this;
	*this = Form(other);
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

unsigned int Form::getGradeSign() const {
	return this->_gradeSign;
}

unsigned int Form::getGradeExec() const {
	return this->_gradeExec;
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException("grade required to sign the form is higher!\n");
	this->_signed = true;
	std::cout << bur.getName() << " signed " << this->getName() << std::endl;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : _message(msg){}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw() {
	return _message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : _message(msg){}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

std::ostream& operator<<(std::ostream& o, const Form& form) {
	o << "Name:             " << form.getName() << "\n"
	  << "Status:           " << (form.getSigned() ? "signed\n" : "not signed\n")
	  << "Grade to sign:    " << form.getGradeSign() << "\n"
	  << "Grade to execute: " << form.getGradeExec() << std::endl;
	return o;
}