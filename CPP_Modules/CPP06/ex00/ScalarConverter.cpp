#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {(void)other; return *this;}

ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string& str) {
	return (str.length() == 1 && !isdigit(str.at(0)));
}

bool isInteger(const std::string& str) {
	if (str.empty()) return false;
	int number;
	std::stringstream ss(str);
	ss >> number;
	if (ss.fail()) return false;
	std::size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < str.length()) {
		if (!isdigit(str[i])) return false;
		i++;
	}
	return true;
}

bool isFloat(const std::string& str) {
	if (str.empty()) return false;
	if (str == "inff" || str == "-inff" || str == "+inff" || str == "nanf") return true;
	if (str.at(str.length() - 1) != 'f') return false;
	if (str.length() == 2 && str.at(1) != 'f') return false;
	float number;
	std::stringstream ss(str.substr(0, str.length() - 1));
	ss >> number;
	if (ss.fail()) return false;
	bool dot = 0;
	std::size_t i = 0;
	if (str[i] == '+' || str[i] == '-') i++;
	while (i < str.length() - 1) {
		if (!dot && !isdigit(str[i]) && str[i] == '.') dot = true;
		else if (dot && !isdigit(str[i])) return false;
		i++;
	}
	return dot;
}

bool isDouble(const std::string& str) {
	if (str.empty()) return false;
	if (str == "inf" || str == "-inf" || str == "+inf" || str == "nan") return true;
	if (str.length() < 2) return false;
	double number;
	std::stringstream ss(str);
	ss >> number;
	if (ss.fail()) return false;
	bool dot = 0;
	std::size_t i = 0;
	if (str[i] == '+' || str[i] == '-') i++;
	while (i < str.length()) {
		if (!dot && !isdigit(str[i]) && str[i] == '.') dot = true;
		else if (dot && !isdigit(str[i])) return false;
		i++;
	}
	return dot;
}

void convertChar(char c) {
	if (isprint(c)) std::cout << "char: '" << c << "'\n";
	else std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(c)
			<< "\nfloat: " << std::fixed << std::setprecision(1) 
			<< static_cast<float>(c) << "f\n"
			<< "double: " << static_cast<double>(c) << "\n";
}

void convertInteger(const std::string& num) {
	int number;
	std::stringstream ss(num);
	ss >> number;
	if (number >= 32 && number < 127) std::cout << "char: '" << static_cast<char>(number) << "'\n";
	else if ((number >= 0 && number < 32) || number == 127) std::cout << "char: Non displayable\n";
	else std::cout << "char: impossible\n";
	std::cout << "int: " << number << "\n"
			  << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>(number) << "f\n"
			  << "double: " << static_cast<double>(number) << "\n";
}

float checkFloatLiterals(const std::string& literal) {
	if (literal == "inff" || literal == "+inff") return std::numeric_limits<float>::infinity();
	else if (literal == "-inff") return -std::numeric_limits<float>::infinity();
	else if (literal == "nanf") return std::numeric_limits<float>::quiet_NaN();
	else return  strtof(literal.substr(0, literal.length() - 1).c_str(), NULL);  
}

void convertFloat(const std::string& num) {
	float number;
	number = checkFloatLiterals(num);
	if (std::isnan(number) || std::isinf(number) || number < 0 || number > 127)
		std::cout << "char: impossible\n";
	else if (number >= 32 && number < 127) 
		std::cout << "char: '" << static_cast<char>(number) << "'\n";
	else std::cout << "char: Non displayable\n";
	if (std::isnan(number) || std::isinf(number) 
		|| number > static_cast<float>(std::numeric_limits<int>::max()) 
		|| number < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible\n";
	else std::cout << "int: " << static_cast<int>(number) << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) 
			  << number << "f\n"
			  << "double: " << static_cast<double>(number) << "\n";
}

double checkDoubleLiterals(const std::string& literal) {
	if (literal == "inf" || literal == "+inf") return std::numeric_limits<double>::infinity();
	else if (literal == "-inf") return -std::numeric_limits<double>::infinity();
	else if (literal == "nan") return std::numeric_limits<double>::quiet_NaN();
	else return  strtod(literal.c_str(), NULL);  
}

void convertDouble(const std::string& num) {
	double number;
	number = checkDoubleLiterals(num);
	if (std::isnan(number) || std::isinf(number) || number < 0 || number > 127)
		std::cout << "char: impossible\n";
	else if (number >= 32 && number < 127) 
		std::cout << "char: '" << static_cast<char>(number) << "'\n";
	else std::cout << "char: Non displayable\n";
	if (std::isnan(number) || std::isinf(number) 
		|| number > static_cast<double>(std::numeric_limits<int>::max()) 
		|| number < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible\n";
	else std::cout << "int: " << static_cast<int>(number) << "\n";
	if ((number > std::numeric_limits<float>::max() || 
		number < std::numeric_limits<float>::min()) 
		&& !(std::isnan(number) || std::isinf(number)))
		std::cout << "float: impossible\n" ;
	else std::cout << "float: " << std::fixed << std::setprecision(1) 
			  << static_cast<float>(number) << "f\n";
	std::cout << "double: " << number << "\n";
}

void ScalarConverter::convert(const std::string& literal) {
	if (isChar(literal)) convertChar(static_cast<char>(literal[0]));
	else if (isInteger(literal)) convertInteger(literal);
	else if (isFloat(literal)) convertFloat(literal);
	else if (isDouble(literal)) convertDouble(literal);
	else std::cout << "char:   impossible\n"
				  << "int:    impossible\n"
				  << "float:  impossible\n"
				  << "double: impossible\n";
}

