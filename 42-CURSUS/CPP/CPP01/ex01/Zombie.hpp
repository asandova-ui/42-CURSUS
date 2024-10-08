/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:41:27 by alonso            #+#    #+#             */
/*   Updated: 2024/10/07 21:41:34 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    
private:
    std::string _name;
public:
    Zombie();
    ~Zombie();
    void    announce( void );
    Zombie* newZombie( std::string name );
    void    setName( std::string name );
};

Zombie*    zombieHorde( int N, std::string name );

#endif