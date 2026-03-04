#pragma once

#include <iostream>

class Fixed
{
    private:
        // Stores the fixed-point value as raw bits
        int                 _fixedPointValue;

        // Number of fractional bits (always 8 in this exercise)
        static const int    _fractionalBits = 8;

    public:
        // Orthodox Canonical Form
        Fixed();                     // Default constructor
        Fixed(const Fixed& other);   // Copy constructor - creates a new object as a copy of an existing object
        Fixed& operator=(const Fixed& other); // Copy assignment operator - copies values from one existing object into another existing object
        ~Fixed();                    // Destructor

        int  getRawBits(void) const;
        void setRawBits(int const raw);
};
