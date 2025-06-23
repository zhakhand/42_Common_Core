#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"){
	_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Bureaucrat can't have grade lower than 150!\n");
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Bureaucrat can't have grade higher than 1!\n");
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade()){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other) return *this;
	*this = Bureaucrat(other);
	return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName() const{
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::increaseGrade(){
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException("Bureaucrat can't have grade higher than 1!\n");
	this ->_grade -= 1;
}

void Bureaucrat::decreaseGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException("Bureaucrat can't have grade lower than 150!\n");
	this->_grade += 1;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		throw Bureaucrat::GradeTooLowException(this->getName() 
			+ " couldn't sign " 
			+ form.getName()
			+ " because "
			+ e.what());
	}
}

void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << "Form failed to execute because ";
		throw GradeTooLowException(e.what());
		return;
	}
	std::cout << this->getName() << " executed " << form.getName() << "\n";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : _message(msg){}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : _message(msg){}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bur) {
	o << bur.getName() << ", " << "bureaucrat grade " << bur.getGrade() << std::endl;
	return o;
}
