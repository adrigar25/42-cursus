# Ejecutable
NAME = so_long

# Directorios de librerías
GNL_DIR = gnl
PRINTF_DIR = ft_printf
MLX_DIR = mlx
LIBFT_DIR = libft

# Libs
GNL_LIB = $(GNL_DIR)/libgnl.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Fuentes propias
SRCS = main.c utils.c game.c map_utils.c
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# MiniLibX flags
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Regla principal
all: $(MLX_LIB) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

# Compilar libs
$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

# .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -Iincludes -I$(GNL_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(GNL_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re