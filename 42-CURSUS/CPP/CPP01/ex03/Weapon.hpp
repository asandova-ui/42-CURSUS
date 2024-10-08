/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:45:38 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 13:48:59 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon( std::string type );
    ~Weapon();
    const std::string&  getType( void );
    void                setType( std::string newType );
};
#endif