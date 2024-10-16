/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:20:45 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:22:11 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
    Brain   *_brain;

public:
    Dog( void );
    ~Dog( void );

    Dog( const Dog& src );
    Dog& operator=( const Dog& src );

    void   makeSound( void ) const;
};

#endif