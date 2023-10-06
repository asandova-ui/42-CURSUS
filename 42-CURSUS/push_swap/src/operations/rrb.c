/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:28:06 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 12:29:27 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top > 0)
	{
		temp = b->array[b->top];
		i = b->top;
		while (i > 0)
		{
			b->array[i] = b->array[i - 1];
			i--;
		}
		b->array[0] = temp;
	}
}