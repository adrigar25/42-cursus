NAME = push_swap

LIBFT_DIR = ./libs/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -I$(LIBFT_DIR)

MANDATORY_DIR = ./src/mandatory

SRCS = \
	$(MANDATORY_DIR)/main.c \
	$(MANDATORY_DIR)/algorithms/small_sort.c \
	$(MANDATORY_DIR)/algorithms/big_sort.c \
	$(MANDATORY_DIR)/utils/stack_add_utils.c \
	$(MANDATORY_DIR)/utils/stack_remove_utils.c \
	$(MANDATORY_DIR)/utils/stack_utils.c \
	$(MANDATORY_DIR)/utils/validation_utils.c \
	$(MANDATORY_DIR)/utils/utils.c \
	$(MANDATORY_DIR)/ops/push.c \
	$(MANDATORY_DIR)/ops/swap.c \
	$(MANDATORY_DIR)/ops/rotate/forward/ra.c \
	$(MANDATORY_DIR)/ops/rotate/forward/rb.c \
	$(MANDATORY_DIR)/ops/rotate/forward/rr.c \
	$(MANDATORY_DIR)/ops/rotate/reverse/rra.c \
	$(MANDATORY_DIR)/ops/rotate/reverse/rrb.c \
	$(MANDATORY_DIR)/ops/rotate/reverse/rrr.c \
	$(MANDATORY_DIR)/ops/rotate/rotate.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_LIB):
	make bonus -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT_LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re