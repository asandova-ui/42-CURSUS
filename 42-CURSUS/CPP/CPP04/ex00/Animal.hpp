/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:51:47 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:02:35 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected: 
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();

        Animal( const Animal &other);
        Animal& operator=( const Animal& other );

        virtual void makeSound ( void ) const;
        std::string getType( void ) const;
};

#endif