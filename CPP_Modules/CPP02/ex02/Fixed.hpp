#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <cmath>
#include <iostream>

class Fixed {
private:
	int _number;
	static const int _frac_bits = 8;
public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	/*    COMPARISON OPS      */
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);
	bool operator<(const Fixed& other);
	bool operator>(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator>=(const Fixed& other);

	Fixed operator+(const Fixed& rhs);
	Fixed operator-(const Fixed& rhs);
	Fixed operator*(const Fixed& rhs);
	Fixed operator/(const Fixed& rhs);

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif