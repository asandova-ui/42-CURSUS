/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:11:40 by alonso            #+#    #+#             */
/*   Updated: 2024/10/16 09:38:44 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain( void );
    ~Brain( void );
    Brain( const Brain& src );
    Brain& operator=( const Brain& rhs );
};
 
#endif