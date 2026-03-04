/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:06:24 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 19:51:20 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
Fixed-point representation stores a number as an integer, but reserves some bits for the fractional part.
With 8 fractional bits, we effectively multiply the number by 256 (2^8) to store it.

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
    // Example: 42.42 * 256 = 10859.52 → roundf() = 10860
    // This keeps both the integer part (42) and fractional part (0.42)
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}    


// -----------------------------------------------------
// *** GETTER & SETTER ***
// -----------------------------------------------------

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

