/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:05:39 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 12:15:06 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../printf/libft/libft.h"

void	arg_checker(int argc, char **argv)
{
	if (argc == 1)
		ft_error("Error: no has cargado ningún mapa");
	if (argc > 2)
		ft_error("Error: too many arguments");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("Error: extensión incorrecta, introducir un .ber");
	}
	else
		ft_error("Error: extensión incorrecta");
}