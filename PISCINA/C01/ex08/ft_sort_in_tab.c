/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:38:41 by asandova          #+#    #+#             */
/*   Updated: 2023/08/14 14:48:23 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	prev;
	int	next;

	prev = 0;
	next = 0;
	while (prev < size)
	{
		while (next < size)
		{
			if (tab[prev] > tab[next])
			{
				temp = tab[prev];
				tab[prev] = tab[next];
				tab[next] = temp;
			}
			next ++;
		}
		prev ++;
		next = prev + 1;
	}
}
