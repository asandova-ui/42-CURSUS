/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:06:31 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:10:20 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
        std::cout << this->_type << " constructor called" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << this->_type << " destructor called" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "wofwof!" << std::endl;
}