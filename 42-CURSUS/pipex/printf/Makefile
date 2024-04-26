
SRCS = src/ft_printf.c src/format_handlers/ft_itoabase.c src/format_handlers/ft_uitoa.c src/format_handlers/print_character.c src/format_handlers/print_integer.c src/format_handlers/print_highhex.c src/format_handlers/print_lowhex.c src/format_handlers/print_nosign.c src/format_handlers/print_ptrhexa.c src/format_handlers/print_string.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft