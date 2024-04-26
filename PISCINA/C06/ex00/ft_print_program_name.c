/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:02:55 by asandova          #+#    #+#             */
/*   Updated: 2023/08/24 18:00:03 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_program_name(char *print)
{
	int	i;

	i = 0;
	while (print[i] != '\0')
	{
		write (1, &print[i], 1);
		i ++;
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	ft_print_program_name(argv[0]);
	return (0);
}
