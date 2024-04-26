/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:00:07 by manorteg          #+#    #+#             */
/*   Updated: 2023/08/27 23:20:38 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alll.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str >= ' ' && *str <= '~')
			str++;
		else
			return (0);
	}
	return (1);
}

int	save_word(t_map *map, char *num_start, int colons_count)
{
	char	*word_start;
	int		word_length;

	word_start = num_start;
	while (*word_start == ' ' || *word_start == ':')
	{
		if (*word_start == ':')
			if (++colons_count > 1)
				return (2);
		word_start++;
	}
	if (!is_printable(word_start) || colons_count == 0)
		return (2);
	word_length = ft_strlen(word_start);
	map->word = malloc(word_length + 1);
	ft_strncpy(map->word, word_start, word_length);
	return (1);
}

int	save_number(t_map *map, char *line, char **num_start, int *colons_count)
{
	(*colons_count) = 0;
	(*num_start) = line;
	if (!is_digit(*(*num_start)))
		return (2);
	while (is_digit(*(*num_start)))
		(*num_start)++;
	if (*(*num_start) != ' ' && *(*num_start) != ':')
		return (2);
	map->length = (*num_start) - line;
	map->number = malloc(map->length + 1);
	ft_strncpy(map->number, line, map->length);
	return (1);
}

int	fill_map(t_map *map, char *line)
{
	char	*num_start;
	int		colons_count;

	if (save_number(map, line, &num_start, &colons_count) == 2)
		return (2);
	return (save_word(map, num_start, colons_count));
}
