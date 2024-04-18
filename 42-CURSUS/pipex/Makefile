SRCS = main.c utils.c

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF_PATH = ./ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = pipex

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS)  -o $(NAME) $(LIBFTPRINTF) 

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFTPRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re