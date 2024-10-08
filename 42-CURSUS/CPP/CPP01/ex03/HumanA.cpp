/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:45:56 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 13:51:08 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack( void ) const
{
    if (this->_weapon.getType() != "")
    
        std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
}