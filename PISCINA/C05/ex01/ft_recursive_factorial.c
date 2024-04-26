/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:41:01 by asandova          #+#    #+#             */
/*   Updated: 2023/08/21 10:53:12 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int num)
{
	if (num < 0)
	{
		return (0);
	}
	if (num == 0)
	{
		return (1);
	}
	else
		return (num * ft_recursive_factorial(num - 1));
}
/*int	main(void)
{
	printf("%i" , ft_recursive_factorial(5));
	return(0);
}*/
