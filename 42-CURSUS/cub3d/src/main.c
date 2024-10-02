/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:44:27 by alonso            #+#    #+#             */
/*   Updated: 2024/09/29 13:07:58 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int parse_args(t_data *data, char **argv)
{
    if (check_file(argv[1], true) == 1)
		clean_exit(data, 1);
	parse_data(argv[1], data);
	if (get_file_data(data, data->mapinfo.file) == 1)
		return (free_data(data));
	if (check_map_validity(data, data->map) == 1)
		return (free_data(data));
	if (check_textures_validity(data, &data->texinfo) == 1)
		return (free_data(data));
	init_player_direction(data);
	if (DEBUG_MSG)
		debug_display_data(data);
	return (0);
}

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
        return(custom_error("Numero incorrecto de parametros", "dale bien", 1));
    init_data(&data);
    if (parse_args(&data, argv) != 0)
		return (1);
	init_mlx(&data);
	init_textures(&data);
	render_images(&data);
	listen_for_input(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
