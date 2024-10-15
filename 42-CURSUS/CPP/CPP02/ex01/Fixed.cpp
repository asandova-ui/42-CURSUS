/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:34:20 by alonso            #+#    #+#             */
/*   Updated: 2024/10/15 13:10:52 by alonso           ###   ########.fr       */
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
    //this->setRawBits(other.getRawBits());
    *this = other;
}

Fixed &Fixed::operator=( const Fixed &other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointNumberValue = other.getRawBits();
    return *this;
}

Fixed::Fixed( int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointNumberValue = value << _nBits;
}

Fixed::Fixed( float const value)
{    
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointNumberValue = roundf(value *(1 << _nBits));
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

float   Fixed::toFloat( void ) const
{
    return static_cast<float>( this->getRawBits() ) / ( 1 << _nBits );
}

int     Fixed::toInt( void ) const
{
    return this->_fixedPointNumberValue >> _nBits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}