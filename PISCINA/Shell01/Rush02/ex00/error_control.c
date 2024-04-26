/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:20:26 by asandova          #+#    #+#             */
/*   Updated: 2023/08/27 22:19:14 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alll.h"

char	*check_param(int argc, char **argv)
{
	char	*dic_name;

	dic_name = malloc(sizeof(char) * 30);
	dic_name = "";
	if (argc == 2)
	{
		if (check_num(argv[1]) == 0)
			return (dic_name);
		dic_name = "numbers.dict";
		return (dic_name);
	}
	else if (argc == 3)
	{
		if (check_num(argv[2]) == 0)
			return (dic_name);
		return (argv[1]);
	}
	else
		return (dic_name);
}

int	check_num(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] == 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == 32)
		i++;
	len = ft_strlen(str);
	if (len == i)
		return (1);
	return (0);
}

int	file_valid(char *dic_name, t_map map[100])
{
	char	buffer[1];
	char	line[100];
	int		file_descriptor;
	int		line_position;
	int		map_count;

	map_count = 0;
	file_descriptor = open(dic_name, O_RDONLY);
	while (read(file_descriptor, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
		{
			line[line_position] = '\0';
			if (fill_map(&map[map_count], line) == 2)
				return (2);
			map_count++;
			line_position = 0;
		}
		else
			line[line_position++] = buffer[0];
	}
	if (close(file_descriptor) == -1)
		return (0);
	return (1);
}
