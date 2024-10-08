/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:15:52 by alonso            #+#    #+#             */
/*   Updated: 2024/10/07 21:20:57 by alonso           ###   ########.fr       */
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
        Zombie( std::string name );
        ~Zombie();
        void announce(void);
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

#endif