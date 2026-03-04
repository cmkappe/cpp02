/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:01:14 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 21:07:26 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// the < operator compares raw fixed-point values directly, which works because they are scaled by the same factor (256)

bool Fixed::operator>(const Fixed& other) const
{
    return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_fixedPointValue != other._fixedPointValue);
}
