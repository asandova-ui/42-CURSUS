/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:43:31 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:49:26 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template< typename T >
void    swap( T& a, T& b ) {
    T tmp = a;
    a = b;
    b = tmp;
}

template< typename T >
T       min( T& a, T& b ) {
    return ( a < b ? a : b );
}

template< typename T >
T       max( T& a, T& b ) {
    return ( a > b ? a : b );
}

#endif