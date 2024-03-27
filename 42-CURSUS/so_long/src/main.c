/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:55:18 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 11:34:48 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_prog(char *map)
{
	error_control(map);
}

int	main(int argc, char **argv)
{
	arg_checker(argc, argv);
	start_prog(argv[1]);
	return (0);
}
