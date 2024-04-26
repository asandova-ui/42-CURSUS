/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:48:07 by asandova          #+#    #+#             */
/*   Updated: 2023/08/11 12:27:03 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	div;

	div = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb / div >= 10)
	{
		div *= 10;
	}
	while (div > 0)
	{
		write(1, &(char){nb / div + '0'}, 1);
		nb %= div;
		div /= 10;
	}
}
