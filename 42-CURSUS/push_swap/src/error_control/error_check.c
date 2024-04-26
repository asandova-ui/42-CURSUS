/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:28:15 by asandova          #+#    #+#             */
/*   Updated: 2024/04/26 14:32:56 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../printf/includes/ft_printf.h"
#include "../../printf/libft/libft.h"

int	check_args(char **args, int argc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;

	error_control(argc + 1, args);
	while (++i < argc)
	{
		if (check_num(args[i + 1]) == -1 || *args[i + 1] == '\0')
			return (-1);
	}
	while (++j < argc)
	{
		if (check_int(args[j + 1]) == -1)
			return (-1);
	}
	return (0);
}