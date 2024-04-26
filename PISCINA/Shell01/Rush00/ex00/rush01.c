/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:56:12 by asandova          #+#    #+#             */
/*   Updated: 2023/08/12 12:09:18 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	aprint_line(int x, char start, char inter, char final)
{
	int	j;

	j = 1;
	while (j <= x)
	{
		if (j == 1)
			ft_putchar(start);
		else if (j == x)
			ft_putchar(final);
		else
			ft_putchar(inter);
		j ++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x != 0 && y != 0)
	{
		while (i <= y)
		{
			if (i == 1)
				aprint_line(x, '/', '*', '\\');
			else if (i == y)
				aprint_line(x, '\\', '*', '/');
			else
				aprint_line(x, '*', ' ', '*');
			i ++;
		}
	}
}
