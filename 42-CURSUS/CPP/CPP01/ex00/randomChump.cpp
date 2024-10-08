/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    randomChump.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:37 by alonso            #+#    #+#             */
/*   Updated: 2024/10/07 21:21:46 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    randomChump( std::string name )
{
    Zombie  zombi( name );
    zombi.announce();
}