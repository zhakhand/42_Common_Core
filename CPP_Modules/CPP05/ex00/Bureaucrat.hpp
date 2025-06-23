#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string _name;
	unsigned int _grade;
	Bureaucrat();

public:
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	const std::string getName() const;
	unsigned int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	
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

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bur);

#endif