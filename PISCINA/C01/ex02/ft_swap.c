/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:11:18 by asandova          #+#    #+#             */
/*   Updated: 2023/08/11 09:55:41 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	inter1;

	inter1 = *a;
	*a = *b;
	*b = inter1;
}
/*int	main(void)
{
	int *a;
	int *b;
	int print_a;
	int print_b;

	a = &print_a;
	b = &print_b;
	
	print_a =12;
	print_b =55;
	ft_swap(a,b);

	printf("%d",print_a);
	printf("%d",print_b);
}*/