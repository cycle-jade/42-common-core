#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
    os << fixed.toFloat();
    return os;
}
Fixed::Fixed() : fixedPointValue(0)
{
     std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" <<  std::endl;
    this->fixedPointValue = other.getRawBits();
}

Fixed::Fixed(int const n) : fixedPointValue(0)  
{
     std::cout << "Int constructor called" << std::endl;
    fixedPointValue = n << fractionalBits;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = static_cast<int>(roundf(f * (1 << fractionalBits)));
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}
int Fixed::toInt(void) const {
    return this->fixedPointValue >> this->fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}