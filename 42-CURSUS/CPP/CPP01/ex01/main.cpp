/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:41:57 by alonso            #+#    #+#             */
/*   Updated: 2024/10/07 21:43:47 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 10

int main( void )
{
    Zombie *zombiz = zombieHorde(N, "zombi");

    for (int i = 0; i < N; i++)
    {
        zombiz[i].announce();
    }

    delete [] zombiz;
    return 0;
}