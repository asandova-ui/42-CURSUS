/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:20:41 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:29:12 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
    std::cout << this->_type << " constructor called" << std::endl;
    try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
    }
}

Cat::~Cat( void )
{
    std::cout << this->_type << " destructor called" << std::endl;
    delete  this->_brain;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}

Cat::Cat( const Cat& src ) : Animal(src)
{
    *this = src;
}

Cat& Cat::operator=( const Cat& src )
{
    std::cout << "Cat copy called." << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        this->_brain = new Brain( *src._brain );
    }
    return *this;
}
