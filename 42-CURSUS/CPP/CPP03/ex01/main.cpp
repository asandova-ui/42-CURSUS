/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:25:35 by alonso            #+#    #+#             */
/*   Updated: 2024/10/15 13:38:15 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap ash( "Ash" );
    ScavTrap ash2( ash );

    ash.attack( "the air" );
    ash.takeDamage( 10 );
    ash.beRepaired( 10 );
    ash.guardGate();

    return EXIT_SUCCESS;
}