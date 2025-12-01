NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra

MANDATORY_DIR = src/

SRCS = $(MANDATORY_DIR)/pipex.c \
       $(MANDATORY_DIR)/exec/run_cmd.c \
       $(MANDATORY_DIR)/exec/get_cmd_path.c \
       $(MANDATORY_DIR)/parse/cmd_parse.c \
       $(MANDATORY_DIR)/parse/quotes.c \
       $(MANDATORY_DIR)/utils/ft_open_file.c \
       $(MANDATORY_DIR)/utils/ft_redir_in_out.c \
       $(MANDATORY_DIR)/utils/my_getenv.c \
       $(MANDATORY_DIR)/utils/free.c

OBJS = $(SRCS:.c=.o)


LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = libs/gnl
GNL = $(GNL_DIR)/libgnl.a


all: $(LIBFT) $(GNL) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)

%.o: %.c $(MANDATORY_DIR)/pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
