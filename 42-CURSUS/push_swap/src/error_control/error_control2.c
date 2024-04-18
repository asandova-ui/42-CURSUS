/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:55 by asandova          #+#    #+#             */
/*   Updated: 2024/04/18 15:29:01 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../printf/includes/ft_printf.h"
#include "../../printf/libft/libft.h"

int	check_int(char *s)
{
	size_t	res;
	int		i;

	res = 0;
	i = -1;
	if (s[i + 1] != '-')
	{
		while (s[++i])
			res = (res * 10) + s[i] - 48;
		if (res > 2147483647)
			return (-1);
	}
	else
	{
		i++;
		while (s[++i])
			res = (res * 10) + s[i] - 48;
		if (res > 2147483648)
			return (-1);
	}
	return (0);
}

int	check_num(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((s[j] == '-' && (s[j + 1] >= '0' && s[j + 1] <= '9')) || (s[j] >= '0'
			&& s[j] <= '9'))
	{
		i++;
		j++;
		while (s[j])
		{
			if (s[j] >= '0' && s[j] <= '9')
				i++;
			j++;
		}
	}
	if (i == ft_strlen(s))
		return (0);
	return (-1);
}

int	check_args(char **args, int argc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < argc)
	{
		if (check_num(args[i + 1]) == -1 || *args[i + 1] == '\0')
		{
			return (-1);
		}
	}
	while (++j < argc)
	{
		if (check_int(args[j + 1]) == -1)
		{
			return (-1);
		}
	}
	return (0);
}
