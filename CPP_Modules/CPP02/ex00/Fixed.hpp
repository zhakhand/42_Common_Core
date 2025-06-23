#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed {
private:
	int _number;
	static const int _frac_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator =(const Fixed& other);
	bool operator==(const Fixed& other);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif