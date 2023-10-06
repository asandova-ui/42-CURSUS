/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:47:03 by asandova          #+#    #+#             */
/*   Updated: 2023/10/06 15:33:24 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/includes/ft_printf.h"

/*int	partition(t_stack *a, int low, int high)
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
}*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] <= pivot)
            i++;

        while (arr[j] >= pivot && j >= i)
            j--;

        if (j < i)
            break;

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void	algorithm(t_stack *a, t_stack *b)
{
	sort_stack(a, b);
}
