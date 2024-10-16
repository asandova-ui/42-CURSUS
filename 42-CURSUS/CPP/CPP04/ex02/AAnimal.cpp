/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:35:27 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:43:40 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "AAnimel" )
{
    std::cout << this->_type << " constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type( type )
{
    std::cout << "AAnimal " << this->_type << " constructor called" << std::endl;
}

AAnimal::~AAnimal( void )
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& src )
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
}

AAnimal& AAnimal::operator=( const AAnimal& rhs )
{
    std::cout << "<AAnimal.cpp:35: AAnimal assignment operator called" << std::endl;
    if ( this != &rhs ) {
        this->_type = rhs._type;
    }
    return *this;
}

void AAnimal::makeSound( void ) const
{
    std::cout << "AAnimal makeSound called" << std::endl;
}

std::string    AAnimal::getType( void ) const
{
    return this->_type;
}