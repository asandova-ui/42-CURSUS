/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:45:48 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 13:48:54 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon*     _weapon;
public:
    HumanB( std::string name );
    ~HumanB();
    void    attack( void ) const;
    void    setWeapon( Weapon& weapon );
};
#endif