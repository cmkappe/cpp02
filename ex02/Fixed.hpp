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

        // Arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Increment and decrement operators
        Fixed& operator++();    // Prefix increment
        Fixed operator++(int);  // Postfix increment
        Fixed& operator--();    // Prefix decrement
        Fixed operator--(int);  // Postfix decrement

        // Static member functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

