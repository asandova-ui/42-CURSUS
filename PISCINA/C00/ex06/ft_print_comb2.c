/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:58:52 by asandova          #+#    #+#             */
/*   Updated: 2023/08/10 19:18:35 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 99)
	{
		num2 = num1 +1;
		while (num2 <= 99)
		{
			write(1, &(char){num1 / 10 + '0'}, 1);
			write(1, &(char){num1 % 10 + '0'}, 1);
			write(1, " ", 1);
			write(1, &(char){num2 / 10 + '0'}, 1);
			write(1, &(char){num2 % 10 + '0'}, 1);
			if (num1 != 98)
				write(1, ", ", 2);
			num2 ++;
		}
		num1 ++;
	}
}
