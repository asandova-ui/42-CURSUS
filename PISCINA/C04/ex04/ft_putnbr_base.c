/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:24:00 by asandova          #+#    #+#             */
/*   Updated: 2023/08/18 10:36:52 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j ++;
		}
		i ++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	num;

	size = base_check(base);
	if (size == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		num = nbr * -1;
	}
	else
		num = nbr;
	if (num >= size)
	{
		ft_putnbr_base(num / size, base);
		ft_putchar(base[num % size]);
	}
	else
	{
		ft_putchar(base[num % size]);
	}
}

/*int	main(void)
{
	int nbr = 293;
	char *base = "01";
	ft_putnbr_base(nbr, base);
	return (0);
}*/
