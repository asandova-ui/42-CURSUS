/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:13:56 by asandova          #+#    #+#             */
/*   Updated: 2023/08/21 10:38:49 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int num)
{
	int	ret;
	int	i;

	if (num < 0)
	{
		return (0);
	}
	i = 1;
	ret = 1;
	while (i <= num)
	{
		ret *= i;
		i ++;
	}
	return (ret);
}

/*int	main(void)
{
	printf ("%i", ft_iterative_factorial(14));
	return(0);
}*/
