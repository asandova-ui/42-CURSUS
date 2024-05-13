SRCS = src/main.c src/utils.c src/map_proc/valid.c src/map_proc/arg_check.c src/map_proc/init_map.c src/map_proc/init_xpm.c src/map_proc/map_check.c src/map_proc/print_map.c src/map_proc/movement.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF_PATH = ./printf
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

MLX_PATH = ./mmllxx
MLX = $(MLX_PATH)/libmlx.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH)
LDFLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LIBFTPRINTF) $(LDFLAGS) -o $(NAME)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFTPRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
