#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        // Orthodox Canonical Form
        Fixed();                        // Default constructor
        Fixed(const Fixed& other);      // Copy constructor
        Fixed& operator=(const Fixed& other); // Copy assignment operator
        ~Fixed();                       // Destructor

        // Getter & Setter
        int  getRawBits(void) const;
        void setRawBits(int const raw);


    // Conversion constructors (overloaded constructors)
    Fixed(const int n);          // Converts an integer to fixed-point 
    Fixed(const float f);        // Converts a floating-point number to fixed-point

    // Conversion member functions
    float toFloat(void) const;   // Converts the fixed-point value to a floating-point number
    int toInt(void) const;       // Converts the fixed-point value to an integer

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

