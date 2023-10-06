/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:05:14 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 12:19:27 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../printf/includes/ft_printf.h"

void	push(t_stack *s, int value)
{
	if (s->top < MAX_SIZE - 1)
	{
		s->array[++(s->top)] = value;
	}
	else
	{
		ft_printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
}