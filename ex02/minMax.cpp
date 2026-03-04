/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minMax.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:54:30 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 21:21:17 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Static min() and max() functions: Find the smaller or larger of two fixed-point numbers
Each function has two versions:
- One for regular (non-const) Fixed references
- One for const Fixed references (for use with const objects)

Static functions belong to the class itself, not to individual objects.
Called with: Fixed::min(a, b) or Fixed::max(a, b)

Ternary operator (condition) ? value_if_true : value_if_false
*/

// Returns a reference to the smaller of two non-const Fixed objects
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

// Returns a reference to the smaller of two const Fixed objects
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

// Returns a reference to the larger of two non-const Fixed objects
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

// Returns a reference to the larger of two const Fixed objects
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

