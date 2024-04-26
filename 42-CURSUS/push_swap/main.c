/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:23:47 by asandova          #+#    #+#             */
/*   Updated: 2024/04/26 14:32:55 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "printf/includes/ft_printf.h"
#include "printf/libft/libft.h"

void	error_message(char *msg)
{
	(void)msg;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	init_stack(t_list2 **stack, int argc, char **argv)
{
	t_list2	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew2(ft_atoi(args[i]));
		ft_lstadd_back2(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
	{
		free_string(args);
	}
}

static void	sort_stack(t_list2 **stack_a, t_list2 **stack_b)
{
	if (ft_lstsize2(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list2	**stack_a;
	t_list2	**stack_b;

	if (check_args(argv, argc - 1) == -1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (argc < 2)
		return (-1);
	stack_a = (t_list2 **)malloc(sizeof(t_list2));
	*stack_a = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a) == 1)
		exit(EXIT_SUCCESS);
	stack_b = (t_list2 **)malloc(sizeof(t_list2));
	*stack_b = NULL;
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
