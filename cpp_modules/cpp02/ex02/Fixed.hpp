#pragma once
#include <cmath>
#include <iostream>

class Fixed
{
  private:
	int fixedPointValue;
	static const int fractionalBits = 8;

  public:
	Fixed();                   // default constructor
	Fixed(const Fixed &other); // copy constructor
	Fixed(int const n);        // int constructor
	Fixed(float const f);      // float constructor

	Fixed &operator=(const Fixed &other); // copy assignment
	~Fixed();                             // destructor

	float toFloat(void) const;
		// converts the fixed-point value to a floating-point value
	int toInt(void) const;    
		// converts the fixed-point value to an integer value

	int getRawBits(void) const;     // returns the raw fixed-point value
	void setRawBits(int const raw); // sets the raw fixed-point value
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);

	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);

	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;
	Fixed &operator++();
	Fixed operator++(int); 
	Fixed &operator--();
	Fixed operator--(int);
};
std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
