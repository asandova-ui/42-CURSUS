/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:00 by asandova          #+#    #+#             */
/*   Updated: 2023/08/24 17:57:55 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_params(int num, char **print)
{
	int	i;
	int	j;

	i = 0;
	j = num -1;
	while (j >= 1)
	{
		while (print[j][i] != '\0')
		{
			write(1, &print[j][i], 1);
			i ++;
		}
		i = 0;
		write(1, "\n", 1);
		j --;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 0)
		return (0);
	ft_rev_params(argc, argv);
	return (0);
}
