/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:05:51 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 14:08:03 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../printf/includes/ft_printf.h"

int	pop(t_stack *s)
{
	if (s->top >= 0)
	{
		return (s->array[(s->top)--]);
	}
	else
	{
		ft_printf("Stack underflow\n");
		exit(EXIT_FAILURE);
	}
}
