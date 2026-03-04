/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:06:24 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 20:46:01 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// overloads << operator to make printing possible
std::ostream& operator<<(std::ostream& os, const Fixed& f) 
{
    // << operator has no trouble printing int or float, but wouldn't know how to print our custom object,
    // so we define how to print it by converting it to float first
    os << f.toFloat();
    return os; // return for chaining (e.g. std::cout << a << b << c;)
}

// -----------------------------------------------------
// *** CONSTRUCTOR & DESTRUCTOR ***
// -----------------------------------------------------

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) // build a NEW object as a copy of existing object 'other'
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) // Assign state to an ALREADY existing object
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		_fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// -----------------------------------------------------
// *** CONVERSION CONSTRUCTORS ***
// -----------------------------------------------------

/*
Core concept: Store decimal numbers using an integer by scaling them by a power of two

Fixed-point representation stores a number as an integer (thus keeping its benefits, being exact and pretty fast),
but reserves some bits for the fractional part.
With 8 fractional bits, we effectively multiply the number by 256 (2^8) to store it.
_fractionalBits = 8 means 2^8 = 256, so smallest step possible is 1/256 = 0.00390625 (precision)

Example: The number 42.42 in fixed-point:
- Integer part: 42 → stored in upper bits
- Fractional part: 0.42 → stored in lower 8 bits
- Fixed-point value: 42.42 * 256 = 10859.52 → rounded to 10860

To convert back: 10860 / 256 = 42.421875 (close to original 42.42)
*/

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    // Convert integer to fixed-point by shifting left 8 bits (same as multiplying by 256)
    // Example: 42 << 8 = 42 * 256 = 10752
    // The fractional part is 0, so we just scale the integer value
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    // Convert float to fixed-point: multiply by 256 and round to nearest integer
    // (1 << _fractionalBits) calculates 2^8 = 256
    // Example: 42.42 * 256 = 10859.52 → roundf() = 10860 (internally stored)
    // This keeps both the integer part (42) and fractional part (0.42)
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}    


// -----------------------------------------------------
// *** CONVERSION MEMBER FUNCTIONS ***
// -----------------------------------------------------
    
float Fixed::toFloat(void) const
{
    // Convert fixed-point to float: divide by 256
    // Example: 10860 / 256 = 42.421875 (close to original 42.42)
    return ((float)_fixedPointValue / (1 << _fractionalBits)); 
}

int Fixed::toInt(void) const
{
    // Convert fixed-point to integer: shift right 8 bits (same as dividing by 256)
    // Example: 10860 >> 8 = 10860 / 256 = 42 (integer part only)
    return (_fixedPointValue >> _fractionalBits);  
}


// -----------------------------------------------------
// *** GETTER & SETTER ***
// -----------------------------------------------------

int Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

