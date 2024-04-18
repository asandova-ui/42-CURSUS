/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:25 by marvin            #+#    #+#             */
/*   Updated: 2024/04/18 15:00:34 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line.h"
#include "../../includes/so_long.h"
#include "../../printf/libft/libft.h"

static void	floodfill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->columns || y < 0 || y >= map->rows
		|| map->full[y][x] == '1' || map->full[y][x] == 'F')
		return ;
	if (map->full[y][x] == 'E')
	{
		map->full[y][x] = 'F';
		return ;
	}
	map->full[y][x] = 'F';
	floodfill(map, x, y - 1);
	floodfill(map, x, y + 1);
	floodfill(map, x - 1, y);
	floodfill(map, x + 1, y);
}

int	check_route(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->map.player.x;
	y = game->map.player.y;
	floodfill(&game->map, x, y);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.full[i][j] == 'P' || game->map.full[i][j] == 'E'
				|| game->map.full[i][j] == 'C')
			{
				ft_error_free("Mapa imposible de ganar", game);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
