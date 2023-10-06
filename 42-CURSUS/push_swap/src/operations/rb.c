/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:29:52 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 12:31:07 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rb(t_stack *b)
{
	int	i;
	int	temp;

	if (b->top > 0)
	{
		temp = b->array[0];
		i = 0;
		while (i < b->top)
		{
			b->array[i] = b->array[i + 1];
			i++;
		}
		b->array[b->top] = temp;
	}
}