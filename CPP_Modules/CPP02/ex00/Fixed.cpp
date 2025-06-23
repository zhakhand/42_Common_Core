#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _number(0){ std::cout << "Default constructor called\n";}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other; 
}

Fixed &Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	if (*this == other)
		return *this;
	this->setRawBits( other.getRawBits() );
	return *this;
}

bool Fixed::operator==(const Fixed& other) {
	return this->getRawBits() == other.getRawBits();
}

Fixed::~Fixed() {std::cout << "Destructor called\n";}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n"; 
	return this->_number;
}

void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called\n"; 
	this->_number = raw;
}
