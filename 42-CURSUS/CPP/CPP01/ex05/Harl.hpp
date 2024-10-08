/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:17:25 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 14:27:07 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>

class   Harl
{
private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );
public:
    Harl();
    ~Harl();
    void        complain( std:: string level );
};

typedef void (Harl::*t_func) ( void );

#endif