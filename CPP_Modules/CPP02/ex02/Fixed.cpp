#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _number(0){}

Fixed::Fixed(const int number) {
	this->_number = (1 << this->_frac_bits) * number;
}

Fixed::Fixed(const float number) {
	this->_number = roundf(number * (1 << this->_frac_bits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other; 
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (*this == other)
		return *this;
	this->setRawBits( other.getRawBits() );
	return *this;
}

Fixed::~Fixed() {}

bool Fixed::operator==(const Fixed& other) {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) {
	return this->getRawBits() != other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>(const Fixed& other) {
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) {
	return this->getRawBits() >= other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++() {
	this->_number += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_number += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	this->_number -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_number -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed &b) {
	return a <= b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed &b) {
	return a.getRawBits() >= b.getRawBits() ? b : a;
}

Fixed& Fixed::max(Fixed& a, Fixed &b) {
	return a >= b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed &b) {
	return a.getRawBits() >= b.getRawBits() ? a : b;
}


int Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called\n"; 
	return this->_number;
}

void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called\n"; 
	this->_number = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_number) / (1 << this->_frac_bits);
}

int Fixed::toInt(void) const {
	return this->_number >> this->_frac_bits;
}

std::ostream& operator<<(std::ostream &o, const Fixed& fixed) {
	o << fixed.toFloat();
	return o;
}
