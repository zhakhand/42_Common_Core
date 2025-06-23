#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _signed;
	const unsigned int _gradeSign;
	const unsigned int _gradeExec;
public:
	Form();
	Form(const std::string& name, unsigned int gradeSign, unsigned int gradeExec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	const std::string getName() const;
	bool getSigned() const;
	unsigned int getGradeSign() const;
	unsigned int getGradeExec() const;
	void beSigned(const Bureaucrat& bur);

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
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif