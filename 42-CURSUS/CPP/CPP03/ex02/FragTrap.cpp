/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:54:01 by alonso            #+#    #+#             */
/*   Updated: 2024/10/15 13:54:19 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << "| FragTrap | - " << this->_name << " constructed." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "| FragTrap | - " << this->_name << " destructed." << std::endl;
}

void    FragTrap::highFive( void )
{
    if ( this->_energyPoints <= 0 )
    {
        std::cout << "| FragTrap | - " << this->_name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "| FragTrap | - " << this->_name << " high fives everybody." << std::endl;
    this->_energyPoints -= 1;
}