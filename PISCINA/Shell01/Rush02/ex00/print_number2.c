/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:36:14 by asandova          #+#    #+#             */
/*   Updated: 2023/08/27 23:16:13 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alll.h"

int	print_lastname(const t_map *map, int len, int size)
{
	int	i;

	i = -1;
	while (++i < 32 && len >= 3)
	{
		if (map[i].length == len)
		{
			write(1, " ", 1);
			ft_putstr(map[i].word);
			return (1);
		}	
	}
	return (0);
}

void	print_dec(char *num, const t_map *map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (ft_strncmp(map[i].number, num, 2) == 0)
		{
			ft_putstr(map[i].word);
			return ;
		}
	}
}
