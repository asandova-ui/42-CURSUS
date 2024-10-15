/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:18:47 by alonso            #+#    #+#             */
/*   Updated: 2024/10/15 12:30:48 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointNumberValue = 0;
}

Fixed::Fixed( const Fixed &other )
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=( const Fixed &other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointNumberValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointNumberValue;
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointNumberValue = raw;
}