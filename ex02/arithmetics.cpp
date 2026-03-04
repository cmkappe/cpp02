/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetics.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:00:55 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 21:29:01 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Arithmetic operators: +, -, *, /
Each operator performs calculations on the fixed-point values and returns a new Fixed object.

Important:
- For + and -, just add/subtract the raw values (scaling is already built-in)
- For *, we need to divide by 256 because (a*256) * (b*256) = a*b*256^2 (too much scaling)
- For /, we need to multiply by 256 to maintain the same precision


    A = stored value of a
    B = stored value of b
    F = fractional bits (8)

    Addition:       (A + B)
    Subtraction:    (A - B)
    Multiplication: (A * B) >> F
    Division:       (A << F) / B
*/

// Addition: adds the raw fixed-point values
Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

// Subtraction: subtracts the raw fixed-point values
Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

// Multiplication: multiply floating-point values to avoid overflow with raw values
Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

// Division: divide floating-point values to maintain precision
Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}
