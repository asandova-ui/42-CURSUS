/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:56:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 12:15:13 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_game
{
	char	*map;
	int		length;
	int		width;
	int		exit;
	int		items;
	int		pos;

}			t_game;

void		arg_checker(int argc, char **argv);

#endif