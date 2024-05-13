/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:56:14 by marvin            #+#    #+#             */
/*   Updated: 2024/05/13 20:19:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mmllxx/mlx.h"
# include <fcntl.h>
# include "../printf/libft/libft.h"
# include "../printf/includes/ft_printf.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364
# define KEY_ESC  			65307

# define WALL				'1'
# define FLOOR 				'0'
# define ITEM  				'C'
# define PLAYER				'P'
# define EXIT 		 		'E'

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		item;
	t_image		exit;
	t_image		player;
}	t_game;

void	arg_checker(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *argv);
int		ft_error_free(char *message, t_game *game);
char	*ft_strappend(char **s1, const char *s2);
void	ft_init_vars(t_game *game);
void	ft_check_map(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
int		ft_print_map(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
int		ft_close_game(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_init_sprites(t_game *game);
void	ft_free_map(t_game *game);
int		check_route(t_game *game);

#endif