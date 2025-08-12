NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra

MANDATORY_DIR = src/
OBJDIR = objs

SRCS = $(MANDATORY_DIR)/pipex.c \
       $(MANDATORY_DIR)/exec/run_cmd.c \
       $(MANDATORY_DIR)/exec/get_cmd_path.c \
       $(MANDATORY_DIR)/parse/cmd_parse.c \
       $(MANDATORY_DIR)/parse/quotes.c \
       $(MANDATORY_DIR)/utils/ft_open_file.c \
       $(MANDATORY_DIR)/utils/ft_redir_in_out.c \
       $(MANDATORY_DIR)/utils/my_getenv.c \
       $(MANDATORY_DIR)/utils/free.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: %.c $(MANDATORY_DIR)/pipex.h
	mkdir -p $(OBJDIR)/$(dir $*)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re