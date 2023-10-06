/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:06:42 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 12:17:51 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *a)
{
	int	i;
	int	temp;

	if (a->top > 0)
	{
		temp = a->array[0];
		i = 0;
		while (i < a->top)
		{
			a->array[i] = a->array[i + 1];
			i++;
		}
		a->array[a->top] = temp;
	}
}