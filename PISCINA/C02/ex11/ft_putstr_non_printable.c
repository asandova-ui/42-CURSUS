/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:29:09 by asandova          #+#    #+#             */
/*   Updated: 2023/08/15 07:58:40 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_dec_to_hex(unsigned char n)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[n / 16]);
	ft_putchar(base[n % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write (1, &"\\", 1);
			ft_dec_to_hex(str[i]);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}
