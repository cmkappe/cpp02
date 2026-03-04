/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:06:27 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 21:40:16 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
    // ========================================
    // SUBJECT TEST (Required output)
    // ========================================
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    // ========================================
    // ADDITIONAL TESTS
    // ========================================
    
    std::cout << "\n--- Comparison Operators ---" << std::endl;
    {
        Fixed x(10.5f);
        Fixed y(5.25f);
        Fixed z(10.5f);
        
        std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
        std::cout << "x > y: " << (x > y ? "true" : "false") << std::endl;
        std::cout << "x < y: " << (x < y ? "true" : "false") << std::endl;
        std::cout << "x >= z: " << (x >= z ? "true" : "false") << std::endl;
        std::cout << "x == z: " << (x == z ? "true" : "false") << std::endl;
        std::cout << "x != y: " << (x != y ? "true" : "false") << std::endl;
    }
    
    std::cout << "\n--- Arithmetic Operators ---" << std::endl;
    {
        Fixed num1(42.0f);
        Fixed num2(2.0f);
        
        std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
        std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
        std::cout << "num1 - num2 = " << (num1 - num2) << std::endl;
        std::cout << "num1 * num2 = " << (num1 * num2) << std::endl;
        std::cout << "num1 / num2 = " << (num1 / num2) << std::endl;
    }
    
    std::cout << "\n--- Prefix vs Postfix Increment/Decrement ---" << std::endl;
    {
        Fixed val(5.0f);
        std::cout << "val = " << val << std::endl;
        std::cout << "++val = " << ++val << " (val is now " << val << ")" << std::endl;
        std::cout << "val++ = " << val++ << " (val is now " << val << ")" << std::endl;
        std::cout << "--val = " << --val << " (val is now " << val << ")" << std::endl;
        std::cout << "val-- = " << val-- << " (val is now " << val << ")" << std::endl;
    }
    
    std::cout << "\n--- Negative Numbers ---" << std::endl;
    {
        Fixed neg1(-15.5f);
        Fixed neg2(-3.0f);
        
        std::cout << "neg1 = " << neg1 << ", neg2 = " << neg2 << std::endl;
        std::cout << "neg1 + neg2 = " << (neg1 + neg2) << std::endl;
        std::cout << "neg1 * neg2 = " << (neg1 * neg2) << std::endl;
        std::cout << "neg1 < neg2: " << (neg1 < neg2 ? "true" : "false") << std::endl;
    }
    
    std::cout << "\n--- Min and Max Functions ---" << std::endl;
    {
        Fixed m1(100.0f);
        Fixed m2(50.0f);
        const Fixed cm1(75.5f);
        const Fixed cm2(25.5f);
        
        std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
        std::cout << "Fixed::min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
        std::cout << "Fixed::max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;
        
        std::cout << "cm1 = " << cm1 << ", cm2 = " << cm2 << std::endl;
        std::cout << "Fixed::min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
        std::cout << "Fixed::max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;
    }
    
    std::cout << "\n--- Chaining Operations ---" << std::endl;
    {
        Fixed c1(10.0f);
        Fixed c2(2.0f);
        Fixed c3(3.0f);
        
        std::cout << "(c1 + c2) * c3 = " << ((c1 + c2) * c3) << std::endl;
        std::cout << "(c1 - c2) / c2 = " << ((c1 - c2) / c2) << std::endl;
    }
    
    std::cout << "\n--- Epsilon (Smallest Representable Value) ---" << std::endl;
    {
        Fixed eps;
        Fixed one(1.0f);
        
        ++eps;  // epsilon = 1/256 = 0.00390625
        std::cout << "epsilon = " << eps << std::endl;
        std::cout << "1 + epsilon = " << (one + eps) << std::endl;
        std::cout << "(1 + epsilon) > 1: " << ((one + eps) > one ? "true" : "false") << std::endl;
    }
    
    return 0;
}
