/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:06:50 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 12:16:36 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		temp = a->array[a->top];
		i = a->top;
		while (i > 0)
		{
			a->array[i] = a->array[i - 1];
			i--;
		}
		a->array[0] = temp;
	}
}