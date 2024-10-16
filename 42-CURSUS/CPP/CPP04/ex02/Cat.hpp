/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:28:55 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:38:44 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
private:
    Brain   *_brain;

public:
    Cat( void );
    ~Cat( void );

    Cat( const Cat& src );
    Cat& operator=( const Cat& src );

    void   makeSound( void ) const;
};

#endif