/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:44:46 by alonso            #+#    #+#             */
/*   Updated: 2024/10/04 11:08:21 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "../mmllxx/mlx.h"
# include "../printf/libft/libft.h"
# include "../printf/includes/ft_printf.h"
# include "../get_next_line/get_next_line.h"
//DEFINIMOS COLORES QUE VAN A SER DE UTILIDAD

# define RESET	"\e[0m"

# define BOLD	"\e[1m"
# define DIM	"\e[2m"
# define ITAL	"\e[3m"
# define ULINE	"\e[4m"

# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"

# define BRIGHT_BLACK	"\e[90m"
# define BRIGHT_RED		"\e[91m"
# define BRIGHT_GREEN	"\e[92m"
# define BRIGHT_YELLOW	"\e[93m"
# define BRIGHT_BLUE	"\e[94m"
# define BRIGHT_PURPLE	"\e[95m"
# define BRIGHT_CYAN	"\e[96m"
# define BRIGHT_WHITE	"\e[97m"

# define BG_BLACK	"\e[40m"
# define BG_RED		"\e[41m"
# define BG_GREEN	"\e[42m"
# define BG_YELLOW	"\e[43m"
# define BG_BLUE	"\e[44m"
# define BG_PURPLE	"\e[45m"
# define BG_CYAN	"\e[46m"
# define BG_WHITE	"\e[47m"

# define BG_BRIGHT_BLACK	"\e[100m"
# define BG_BRIGHT_RED		"\e[101m"
# define BG_BRIGHT_GREEN	"\e[102m"
# define BG_BRIGHT_YELLOW	"\e[103m"
# define BG_BRIGHT_BLUE		"\e[104m"
# define BG_BRIGHT_PURPLE	"\e[105m"
# define BG_BRIGHT_CYAN		"\e[106m"
# define BG_BRIGHT_WHITE	"\e[107m"

//PARAMETERS MODIFICABLES
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEX_SIZE 64

# ifndef DEBUG_MSG
#  define DEBUG_MSG 0
# endif

# ifndef MMAP_DEBUG_MSG
#  define MMAP_DEBUG_MSG 0
# endif

# ifndef BONUS
#  define BONUS 1
# endif

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
//ESTTRUCTURAS

# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not an .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEX_SIZE 64

# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040

# define MOVESPEED 0.0600
# define ROTSPEED 0.030

# define DIST_EDGE_MOUSE_WRAP 20

/* MINIMAP MACROS */
# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_cubi
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_img		minimap;
}	t_cubi;

typedef struct s_minimap
{
	char	**map;
	t_img	*img;
	int		size;
	int		offset_x;
	int		offset_y;
	int		view_dist;
	int		tile_size;
}	t_minimap;






int	custom_error(char *detail, char *str, int code);
void	init_cubi(t_cubi *cubi);
int	file_validity(char *arg, bool cub);
void	full_exit(t_cubi *cubi, int code);
void	parse_cubi(char *path, t_cubi *cubi);
int	get_cubi_file(t_cubi *cubi, char **map);
void	free_tab(void **tab);
int	fill_color_textures(t_cubi *cubi, t_texinfo *textures, char *line, int j);
void	init_mlx(t_cubi *cubi);
int	free_cubi(t_cubi *cubi);
int	custom_error_val(int detail, char *str, int code);
int	check_textures_validity(t_cubi *cubi, t_texinfo *textures);
void	init_player_direction(t_cubi *cubi);
void	debug_display_data(t_cubi *cubi);
int	check_map_validity(t_cubi *cubi, char **map_tab);
void	init_img_clean(t_img *img);
int	create_map(t_cubi *cubi, char **file, int i);
int	is_a_white_space(char c);
size_t	find_biggest_len(t_mapinfo *map, int i);
void	init_textures(t_cubi *cubi);
void	init_texture_img(t_cubi *cubi, t_img *image, char *path);
int	render(t_cubi *cubi);
void	render_images(t_cubi *cubi);
void	set_image_pixel(t_img *image, int x, int y, int color);
void	init_img(t_cubi *cubi, t_img *image, int width, int height);
void	init_texture_pixels(t_cubi *cubi);
void	init_ray(t_ray *ray);
int	raycasting(t_player *player, t_cubi *cubi);
void	render_minimap_image(t_cubi *cubi, t_minimap *minimap);
void	render_minimap(t_cubi *cubi);
int	move_player(t_cubi *cubi);
void	debug_display_minimap(t_minimap *minimap);
void	update_texture_pixels(t_cubi *cubi, t_texinfo *tex, t_ray *ray, int x);
int	rotate_player(t_cubi *cubi, double rotdir);
int	quit_cub3d(t_cubi *cubi);
int	validate_move(t_cubi *cubi, double new_x, double new_y);
void	listen_for_input(t_cubi *cubi);

#endif