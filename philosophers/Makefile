NAME = philo

CC = cc

CFLAGS = -Werror -Wextra -Wall -pthread

DIR = ./philo

SRCS = $(DIR)/main.c \
       $(DIR)/philo_actions.c \
       $(DIR)/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS)  -o $(DIR)/$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(DIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re