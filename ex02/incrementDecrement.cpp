/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incrementDecrement.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:02:02 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 21:08:14 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Increment and Decrement operators: ++, --
Increase or decrease the fixed-point value by epsilon (ϵ), the smallest representable increment.

Smallest representable ϵ = 1 / (2^8) = 1 / 256 = 0.00390625
This is because _fractionalBits = 8, so each unit in the raw value represents 1/256.

Prefix (++a, --a): Modify the object and return a reference to itself
Postfix (a++, a--): Modify the object but return the old value (before modification)
*/

// Prefix increment: increase by 1 (which represents 1/256 in float)
Fixed& Fixed::operator++()
{
    this->_fixedPointValue += 1;  // Add 1 to raw value = add 1/256 to float value
    return (*this);
}

// Postfix increment: increase by 1, but return the old value
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;  // Save the current state
    this->_fixedPointValue += 1;  // Increment the actual value
    return (temp);  // Return the old state
}

// Prefix decrement: decrease by 1 (which represents 1/256 in float)
Fixed& Fixed::operator--()
{
    this->_fixedPointValue -= 1;  // Subtract 1 from raw value = subtract 1/256 from float value
    return (*this);
}

// Postfix decrement: decrease by 1, but return the old value
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;  // Save the current state
    this->_fixedPointValue -= 1;  // Decrement the actual value
    return (temp);  // Return the old state
}
