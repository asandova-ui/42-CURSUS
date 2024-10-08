/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:45:54 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 13:48:44 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon&     _weapon;
    HumanA();
public:
    HumanA( std::string name, Weapon& weapon );
    ~HumanA();
    void    attack( void ) const;
};

#endif