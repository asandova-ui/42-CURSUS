/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:12:57 by asandova          #+#    #+#             */
/*   Updated: 2023/08/24 17:23:00 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_params(char **argv, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < num)
	{
		while (argv[j][i] != '\0')
		{
			write (1, &argv[j][i], 1);
			i ++;
		}
		i = 0;
		write (1, "\n", 1);
		j ++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 0)
		return (0);
	ft_print_params(argv, argc);
	return (0);
}
