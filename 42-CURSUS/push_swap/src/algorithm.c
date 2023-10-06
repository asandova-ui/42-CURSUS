/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:47:03 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 14:26:06 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/includes/ft_printf.h"

int	partition(t_stack *a, int low, int high)
{
	int	pivot;
	int	i;
	int	temp;
	int	j;

	pivot = a->array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (a->array[j] <= pivot)
		{
			++i;
			temp = a->array[i];
			a->array[i] = a->array[j];
			a->array[j] = temp;
		}
		j ++;
	}
	temp = a->array[i + 1];
	a->array[i + 1] = a->array[high];
	a->array[high] = temp;
	return (i + 1);
}

void	quick_sort(t_stack *a, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(a, low, high);
		quick_sort(a, low, pi - 1);
		quick_sort(a, pi + 1, high);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;
	int	*temp_array;
	int	i;

	size = a->top + 1;
	temp_array = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		temp_array[i] = pop(a);
		i ++;
	}
	quick_sort(a, 0, size - 1);
	i = size - 1;
	while (i >= 0)
	{
		push(a, temp_array[i]);
		i --;
	}
	free(temp_array);
}

void	algorithm(t_stack *a, t_stack *b)
{
	sort_stack(a, b);
}
