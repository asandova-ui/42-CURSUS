/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:41:27 by alonso            #+#    #+#             */
/*   Updated: 2024/09/29 13:07:53 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_top_or_bottom(char **map_tab, int i, int j)
{
	if (!map_tab || !map_tab[i] || !map_tab[i][j])
		return (1);
	while (map_tab[i][j] == ' ' || map_tab[i][j] == '\t'
	|| map_tab[i][j] == '\r' || map_tab[i][j] == '\v'
	|| map_tab[i][j] == '\f')
		j++;
	while (map_tab[i][j])
	{
		if (map_tab[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_map_sides(t_mapinfo *map, char **map_tab)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map_tab, 0, 0) == 1)
		return (1);
	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] != '1')
			return (1);
		i++;
	}
	if (check_top_or_bottom(map_tab, i, 0) == 1)
		return (1);
	return (0);
}

static int	check_map_elements(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '\r'
			|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (custom_error(data->mapinfo.path, "invalid character", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (custom_error(data->mapinfo.path, "more than 1 player", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_position_is_valid(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| is_a_white_space(map_tab[i][j - 1]) == 0
		|| is_a_white_space(map_tab[i][j + 1]) == 0
		|| is_a_white_space(map_tab[i - 1][j]) == 0
		|| is_a_white_space(map_tab[i + 1][j]) == 0)
		return (1);
	return (0);
}

static int	check_player_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (custom_error(data->mapinfo.path, "player sin direccion", 1));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_position_is_valid(data, map_tab) == 1)
		return (custom_error(data->mapinfo.path, "posicion de player invalida", 1));
	return (0);
}

static int	check_map_is_at_the_end(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_validity(t_data *data, char **map_tab)
{
	if (!data->map)
		return (custom_error(data->mapinfo.path, "No hay mapa", 1));
	if (check_map_sides(&data->mapinfo, map_tab) == 1)
		return (custom_error(data->mapinfo.path, "Mapa debe estar rodeado de paredes", 1));
	if (data->mapinfo.height < 3)
		return (custom_error(data->mapinfo.path, "Mapa pequeño, al menos debe ser de 3 alturas", 1));
	if (check_map_elements(data, map_tab) == 1)
		return (1);
	if (check_player_position(data, map_tab) == 1)
		return (1);
	if (check_map_is_at_the_end(&data->mapinfo) == 1)
		return (custom_error(data->mapinfo.path, "Mapa debe ser lo ultimo del fichero", 1));
	return (0);
}
