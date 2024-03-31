SRCS = src/main.c src/utils.c src/map_proc/arg_check.c src/map_proc/init_map.c src/map_proc/init_xpm.c src/map_proc/map_check.c src/map_proc/print_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

LIBFTPRINTF_PATH = ./printf
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

MLX_PATH = ./Mlx
MLX = $(MLX_PATH)/libmlx.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = so_long

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

$(NAME): $(LIBFTPRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFTPRINTF) $(MLX) -framework OpenGL -framework AppKit

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFTPRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re