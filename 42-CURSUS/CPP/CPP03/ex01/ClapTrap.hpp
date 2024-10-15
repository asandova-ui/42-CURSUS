/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:25:33 by alonso            #+#    #+#             */
/*   Updated: 2024/10/15 13:36:37 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>
class ClapTrap
{
protected:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

    ClapTrap();
public:
    ClapTrap( std::string name );
    ~ClapTrap();

    ClapTrap(const ClapTrap &);
    ClapTrap &operator=(const ClapTrap& other);

    void    attack(std::string const& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

};

#endif 