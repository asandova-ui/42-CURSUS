/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:31:31 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:42:35 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"


class AAnimal
{
protected:
    std::string _type;

public:
    AAnimal( void );
    AAnimal( std::string type );
    virtual ~AAnimal( void );

    AAnimal( const AAnimal& src );
    AAnimal& operator=( const AAnimal& rhs );

    virtual void    makeSound( void ) const = 0;;
    std::string     getType( void ) const; 
};

#endif