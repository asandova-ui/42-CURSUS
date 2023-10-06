/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:23:47 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 14:06:43 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/includes/ft_printf.h"

void	initialize(t_stack *s)
{
	s->top = -1;
}

int	is_empty(t_stack *s)
{
	return (s->top == -1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;


	(void)argc;
	(void)argv;
	initialize(&a);
	initialize(&b);
	push(&a, 3);
	push(&a, 1);
	push(&a, 4);
	push(&a, -2);
	push(&a, 8);
	algorithm(&a, &b);
	while (!is_empty(&a))
	{
		ft_printf("%d ", pop(&a));
	}
	return (0);
}
