/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:19:10 by asandova          #+#    #+#             */
/*   Updated: 2023/08/27 23:35:09 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alll.h"

int	main(int argc, char **argv)
{
	int		file_status;
	int		length;
	char	*num;
	char	*dic_name;
	t_map	map[100];

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	num = argv[argc - 1];
	length = ft_strlen(num);
	dic_name = check_param(argc, argv);
	file_status = file_valid(dic_name, map);
	if (file_status == 1)
		printing(num, map);
	if (file_status == 2)
		ft_putstr("Dict Error\n");
	if (file_status == 0)
		ft_putstr("Error\n");
	return (0);
	main2(map, num);
	free(dic_name);
}

void	main2(t_map *map, char *num)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		printf("Número: %s, Palabra: %s\n", map[i].number, map[i].word);
		free(map[i].number);
		free(map[i].word);
		i++;
	}
}

char	*fill_with_zeros(int times, char *filled_num, char *num)
{
	int	i;

	i = 0;
	while (--times >= 0)
		filled_num[i++] = '0';
	return (ft_strcat(filled_num, num));
}

void	printing(char *num, t_map *map)
{
	int		len;
	int		times;
	char	*filled_num;
	char	*start;
	char	*third;

	num = ft_itoa(ft_atoi(num));
	len = ft_strlen(num);
	times = len % 3;
	if (times != 0)
		times = 3 - times;
	filled_num = malloc(sizeof(char) * (len + times));
	third = malloc(sizeof(char) * 4);
	if (!filled_num || !third)
		return ;
	filled_num = fill_with_zeros(times, filled_num, num);
	start = filled_num;
	len = ft_strlen(filled_num);
	printing2(third, filled_num, map, len);
	write(1, "\n", 1);
	free(start);
	free(num);
}

void	printing2(char *third, char *filled_num, t_map *map, int len)
{
	int	i;
	int	cont;
	int	true;

	while (len > 0)
	{
		print_number(ft_strncpy(third, filled_num, 3), map);
		i = 0;
		cont = 0;
		while (third[i] != '\0')
		{
			if (third[i] == '0')
				cont++;
			i++;
		}
		if (cont != 3)
		{
			print_lastname(map, len - 2, 32);
		}
		filled_num += 3;
		len -= 3;
		if (len > 0 || true == 1)
			write(1, " ", 1);
	}
	free(third);
}
