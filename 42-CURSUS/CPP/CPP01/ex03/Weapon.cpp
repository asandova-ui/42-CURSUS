/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:45:40 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 13:50:19 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
    this->setType(type);
}

Weapon::~Weapon()
{
}

const  std::string& Weapon::getType( void )
{
    return this->type;
}

void  Weapon::setType( std::string newType )
{
    this->type = newType;
}