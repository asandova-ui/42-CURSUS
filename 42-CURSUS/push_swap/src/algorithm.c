/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:47:03 by asandova          #+#    #+#             */
/*   Updated: 2023/11/03 12:52:37 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/includes/ft_printf.h"

int	is_sorted(t_stack *stack)
{
	for (int i = 0; i < stack->top - 1; i++)
	{
		if (stack->array[i] > stack->array[i + 1])
		{
			return (0); // No está ordenada
		}
	}
	return (1); // Está ordenada
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_sorted(stack_a))
	{
		if (stack_a->array[0] > stack_a->array[1])
		{
			sa(stack_a);
		}
		else if (stack_a->array[0] > stack_a->array[stack_a->top - 1])
		{
			rra(stack_a);
		}
		else
		{
			pb(stack_a, stack_b);
		}
	}
}

void	algorithm(t_stack *a, t_stack *b)
{
	sort_stack_a(a, b);
}
