NAME = rush-02
SRC = *.c
CC = gcc
CFFLAGS = -Wall -Wextra -Werror

all:
	$(MAKE) $(NAME)
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean: 
	rm -r $(NAME)
fclean:
	$(MAKE) clean
re:
	$(MAKE) fclean
	$(MAKE) all
