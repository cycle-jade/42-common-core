#pragma once
#include <iostream>
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fractionalBits = 8;

public:
    Fixed();                              
    Fixed(const Fixed &other);            
    Fixed(int const n);                   
    Fixed(float const f);                 

    Fixed &operator=(const Fixed &other); 
    ~Fixed();                             
    float toFloat(void) const;   
    int   toInt(void) const;     

    int  getRawBits(void) const;          
    void setRawBits(int const raw);      
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);