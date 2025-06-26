# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 18:24:52 by agarcia           #+#    #+#              #
#    Updated: 2025/06/26 11:06:28 by agarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Ejecutable
NAME = so_long

# Directorios de librerías
GNL_DIR = ./libs/gnl
PRINTF_DIR = ./libs/ft_printf
MLX_DIR = ./libs/mlx
LIBFT_DIR = ./libs/libft
MANDATORY_DIR = ./src/mandatory
BONUS_DIR = ./src/bonus

# Libs
GNL_LIB = $(GNL_DIR)/libgnl.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Fuentes mandatory
SRCS = 	$(MANDATORY_DIR)/main.c \
		$(MANDATORY_DIR)/utils/game/game_utils.c \
		$(MANDATORY_DIR)/utils/player/player_utils.c \
		$(MANDATORY_DIR)/utils/map/map_utils.c \
		$(MANDATORY_DIR)/utils/map/map_checks.c \
		$(MANDATORY_DIR)/utils/error/error_utils.c \
		$(MANDATORY_DIR)/utils/mlx/mlx_utils.c \
		$(MANDATORY_DIR)/utils/input/input_utils.c \
		
# Fuentes bonus
BONUS_SRCS = 	$(BONUS_DIR)/main_bonus.c \
				$(BONUS_DIR)/utils/game/game_utils_bonus.c \
				$(BONUS_DIR)/utils/player/player_utils_bonus.c \
				$(BONUS_DIR)/utils/map/map_utils_bonus.c \
				$(BONUS_DIR)/utils/map/map_checks_bonus.c \
				$(BONUS_DIR)/utils/error/error_utils_bonus.c \
				$(BONUS_DIR)/utils/mlx/mlx_utils_bonus.c \
				$(BONUS_DIR)/utils/input/input_utils_bonus.c \
				$(BONUS_DIR)/utils/enemy/enemy_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# MiniLibX flags
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Regla principal
all: $(MLX_LIB) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

bonus: $(MLX_LIB) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) so_long_bonus

so_long_bonus: $(BONUS_OBJS)
	
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

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
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(LIBFT_LIB)
	rm -f $(GNL_LIB)
	rm -f $(PRINTF_LIB)
	rm -f $(MLX_LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re