# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asandova <asandova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 12:53:55 by asandova          #+#    #+#              #
#    Updated: 2023/10/06 14:28:10 by asandova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(addprefix src/, main.c algorithm.c) $(wildcard src/operations/*.c)

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF_PATH = ./printf
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFTPRINTF)

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