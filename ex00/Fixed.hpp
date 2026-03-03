#pragma once

#include <iostream>

class Fixed
{
    private:
        // Stores the fixed-point value as raw bits.
        int                 _fixedPointValue;

        // Number of fractional bits (always 8 in this exercise).
        static const int    _fractionalBits = 8;

    public:
        // Orthodox Canonical Form
        Fixed();                     // Default constructor
        Fixed(const Fixed& other);   // Copy constructor
        Fixed& operator=(const Fixed& other); // Copy assignment operator
        ~Fixed();                    // Destructor

        // Accessors for the raw fixed-point representation.
        int  getRawBits(void) const;
        void setRawBits(int const raw);
};