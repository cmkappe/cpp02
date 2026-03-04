/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:40:14 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 19:08:39 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Orthodox Canonical Form:

Classes in C++ automatically handle copying and creation
There are 4 functions that define HOW the class should be copied, created, and destroyed.

- Default constructor:
	Initializes a completlly new object with specific default values

- Copy constructor:
	Creates a new object by copying another object's values
	Useful for duplicateion of objects or when passing objects by value

- Copy assignment operator:
	Copies values from one existing object into another existing object
	Different from the copy constructor because both objects already exist.

- Destructor:
	Cleans up when an object is destroyed (goes out of scope or is deleted)
	When a function ends, local objects are destroyed automatically like this`

This form is used to make sure that writing C++ classes is safe and predictable.
*/

// -----------------------------------------------------
// *** CONSTRUCTOR & DESTRUCTOR ***
// -----------------------------------------------------

Fixed::Fixed() : _fixedPointValue(0)
{
	// start with raw fixed-point defaulkt value at 0 so object is always initialized
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue)
{
	// build a NEW object as a copy of existing object 'other', using member initializer list to directly initialize
	std::cout << "Copy constructor called" << std::endl;
}

/* Fixed::Fixed(const Fixed& other)
{
	// build a NEW object as a copy of existing object 'other'
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // *this = other; calls assignment operator, which automatically calls getRawBits() to get the value of other and assign it to this->_fixedPointValue
} */

Fixed& Fixed::operator=(const Fixed& other)
{
	// Assign state to an ALREADY existing object
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 	// checks if we're trying to copy an object to itself (like a = a;)
		_fixedPointValue = other.getRawBits();	// copies data from 'other' to current object (this)	
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// -----------------------------------------------------
// *** MEMBER FUNCTIONS ***
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

