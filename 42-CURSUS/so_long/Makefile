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

# ANSI escape codes for colors and effects
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
BLUE = \033[0;34m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
RESET = \033[0m
BOLD = \033[1m
BLINK = \033[5m

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(MLX) $(OBJS)
	@echo "$(YELLOW)Linking object files and libraries...$(RESET)"
	@$(CC) $(OBJS) $(LIBFTPRINTF) $(LDFLAGS) -o $(NAME) > /dev/null 2>&1
	@echo "$(GREEN)Executable $(NAME) created successfully!$(RESET)"
	@echo "$(MAGENTA)✨✨ Compilation Complete! Enjoy! ✨✨$(RESET)"

$(LIBFTPRINTF):
	@echo "$(BLUE)Building libftprintf library...$(RESET)"
	@make -C $(LIBFTPRINTF_PATH) all > /dev/null 2>&1
	@echo "$(GREEN)libftprintf library built successfully!$(RESET)"

$(MLX):
	@echo "$(BLUE)Building MLX library...$(RESET)"
	@make -C $(MLX_PATH) all > /dev/null 2>&1
	@echo "$(GREEN)MLX library built successfully!$(RESET)"

# Animation for compiling
define compile_animation
	@echo -n "$(CYAN)Compiling: ["
	@for i in `seq 1 25`; do \
		echo -n "="; \
		sleep 0.01; \
	done
	@echo "]$(RESET)"
	@echo "$(BOLD)$(MAGENTA) -> $@ Compiled! $(RESET)"
endef

%.o: %.c
	@echo "$(MAGENTA)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1
	@$(compile_animation)

clean:
	@echo "$(RED)Cleaning object files and libraries...$(RESET)"
	@make -C $(LIBFTPRINTF_PATH) clean > /dev/null 2>&1
	@make -C $(MLX_PATH) clean > /dev/null 2>&1
	@$(RM) $(OBJS)
	@echo "$(GREEN)Cleaned successfully!$(RESET)"

fclean: clean
	@echo "$(RED)Removing executable and all libraries...$(RESET)"
	@make -C $(LIBFTPRINTF_PATH) fclean > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "$(GREEN)Full clean completed successfully!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
