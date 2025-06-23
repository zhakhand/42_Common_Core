#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);

	class InvalidFormException : public std::exception {
	private:
		std::string _message;
	public:
		explicit InvalidFormException(const std::string& msg);
		virtual ~InvalidFormException() throw();
		virtual const char* what() const throw();
	};
};

std::string to_lower(const std::string& str);

#endif