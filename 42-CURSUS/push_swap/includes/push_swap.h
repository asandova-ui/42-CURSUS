/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:55 by asandova          #+#    #+#             */
/*   Updated: 2024/03/18 10:25:59 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list2
{
	int value;
	int index;
	struct s_list2 *next;
}	t_list2;

//fichero main
void	error_message(char *msg);
int	main(int argc, char **argv);
//static void	sort_stack(t_list2 **stack_a, t_list2 **stack_b);
//static void	init_stack(t_list2 **stack, int argc, char **argv);

//fichero de operaciones
//static int	push(t_list2 **stack_to, t_list2 **stack_from);
int	pa(t_list2 **stack_a, t_list2 **stack_b);
int	pb(t_list2 **stack_a, t_list2 **stack_b);

//static int	reverse(t_list2 **stack);
int	rra(t_list2 **stack_a);
int	rrb(t_list2 **stack_b);
int	rrr(t_list2 **stack_a, t_list2 **stack_b);

//static int	rotate(t_list2 **stack);
int	ra(t_list2 **stack_a);
int	rb(t_list2 **stack_b);
int	rr(t_list2 **stack_a, t_list2 **stack_b);

//static int	swap(t_list2 **stack);
int	sa(t_list2 **stack_a);
int	sb(t_list2 **stack_b);
int	ss(t_list2 **stack_a, t_list2 **stack_b);

//control de errores
void	error_control(int argc, char **argv);
//static char	**argc2(char *av);
//static int	ft_isnum(char *num);
//static int	ft_contains(int num, char **argv, int i);

//utils
int	index_distance_head(t_list2 **stack, int index);
int	get_min(t_list2 **stack, int val);
//static t_list2	*get_next_min(t_list2 **stack);
void	index_stack(t_list2 **stack);
int	is_sorted(t_list2 **stack);

//free custom
void	free_string(char **str);
void	free_stack(t_list2 **stack);

//algorithm and simple cases
void	radix_sort(t_list2 **stack_a, t_list2 **stack_b);
//static int	get_max_bits(t_list2 **stack);
void	simple_sort(t_list2 **stack_a, t_list2 **stack_b);
void	sort_5(t_list2 **stack_a, t_list2 **stack_b);
void	sort_4(t_list2 **stack_a, t_list2 **stack_b);

void	sort_3(t_list2 **stack_a);
static void	sort_312(t_list2 **stack_a, t_list2 *head, int min);
static void	sort_231(t_list2 **stack_a, t_list2 *head, int min);
static void	sort_132(t_list2 **stack_a);

//extras
t_list2	*ft_lstnew2(int value);
void	ft_lstadd_back2(t_list2 **stack, t_list2 *new);
int	ft_lstsize2(t_list2 *head);
#endif