# Variables
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS = $(wildcard ft_*.c)
OBJS = $(SRCS:.c=.o)
EXEC = libft
MAIN = main.c

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(NAME) $(MAIN)
<<<<<<< HEAD
	$(CC) $(CFLAGS) $(MAIN) -L. -lft -o $(EXEC)
=======
	$(CC) $(CFLAGS) $(MAIN) -L. -lft -lbsd -o $(EXEC)
>>>>>>> origin/main

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all