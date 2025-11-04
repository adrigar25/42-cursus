NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC_DIR = src
OBJ_DIR = objs

SRCS = main.c \
	   philo.c \
	   actions.c \
	   utils.c \
	   time_utils.c \
	   check.c \
	   monitor.c \
	   mutex_utils.c \
	   sync.c \
	   init.c \

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re