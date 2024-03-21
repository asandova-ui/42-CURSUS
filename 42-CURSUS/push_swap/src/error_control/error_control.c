/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:32:24 by asandova            #+#    #+#             */
/*   Updated: 2023/10/10 09:32:24 by asandova           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../printf/includes/ft_printf.h"
#include "../../printf/libft/libft.h"

/*static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && !num[1])
	{
		return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	**argc2(char *av)
{
	char	**args;

	args = ft_split(av, ' ');
	return (args);
}

void	error_control(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	if (argc == 2)
		args = argc2(argv[1]);
	else
		args = argv;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			error_message("Error");
		if (ft_contains(tmp, args, i) == 1)
			error_message("Error");
		if (tmp < INT_MIN || tmp > 2147483647)
			error_message("Error");
		i++;
	}
	if (argc == 2)
		free_string(args);
}*/

int	check_num(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (
		(s[j] == '-' && (s[j + 1] >= '0' && s[j + 1] <= '9'))
		|| (s[j] >= '0' && s[j] <= '9'))
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

	i = -1;
	while (++i < argc)
	{
		if (check_num(args[i + 1]) == -1 || *args[i + 1] == '\0')
		{
			return (-1);
		}
	}
	return (0);
}