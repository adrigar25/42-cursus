NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC_DIR = src
OBJ_DIR = objs

SRCS = $(SRC_DIR)/main.c \
	   $(SRC_DIR)/philo.c \
	   $(SRC_DIR)/actions.c \
	   $(SRC_DIR)/utils.c \
	   $(SRC_DIR)/time_utils.c \
	   $(SRC_DIR)/check.c \
	   $(SRC_DIR)/monitor.c \
	   $(SRC_DIR)/mutex_utils.c \
	   $(SRC_DIR)/sync.c \
	   $(SRC_DIR)/init.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
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