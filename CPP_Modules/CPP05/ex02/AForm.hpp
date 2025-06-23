#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ctime>
#include <unistd.h>
#include <cstdlib>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const unsigned int _gradeSign;
	const unsigned int _gradeExec;
public:
	AForm();
	AForm(const std::string& name, unsigned int gradeSign, unsigned int gradeExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	const std::string getName() const;
	bool getSigned() const;
	unsigned int getGradeSign() const;
	unsigned int getGradeExec() const;
	void beSigned(const Bureaucrat& bur);
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {
	private:
		std::string _message;
	public:
		explicit GradeTooHighException(const std::string& msg);
		virtual ~GradeTooHighException() throw();
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	private:
		std::string _message;
	public:
		explicit GradeTooLowException(const std::string& msg);
		virtual ~GradeTooLowException() throw();
		virtual const char* what() const throw();
	};

	class FormUnsignedException : public std::exception {
	private:
		std::string _message;
	public:
		explicit FormUnsignedException(const std::string& msg);
		virtual ~FormUnsignedException() throw();
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif