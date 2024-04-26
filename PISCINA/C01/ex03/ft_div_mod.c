/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:26:56 by asandova          #+#    #+#             */
/*   Updated: 2023/08/11 10:56:21 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*int	main(void)
{
	int	a;
	int	b;
	int	x;
	int	y;
	int	*div;
	int	*mod;

	a =10;
	b =5;
	div = &x;
	mod = &y;
	ft_div_mod(a , b, div, mod);
	printf("%d\n", x);
	printf("%d\n", y);
	return (0);
}*/