# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 15:48:06 by agarcia           #+#    #+#              #
#    Updated: 2025/07/01 11:18:48 by agarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Push_spawn
NAME = push_swap

# Lib directories
LIBFT_DIR = ./libs/libft
MANDATORY_DIR = ./src/mandatory

# Libs
LIBFT_LIB = $(LIBFT_DIR)/libft.a

#Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Sources

SRCS = 	$(MANDATORY_DIR)/main.c\
		$(MANDATORY_DIR)/push_swap.c\
		$(MANDATORY_DIR)/ops/push/pa.c\
		$(MANDATORY_DIR)/ops/push/pb.c\
		$(MANDATORY_DIR)/ops/push/push.c\
		$(MANDATORY_DIR)/ops/swap/sa.c\
		$(MANDATORY_DIR)/ops/swap/sb.c\
		$(MANDATORY_DIR)/ops/swap/ss.c\
		$(MANDATORY_DIR)/ops/swap/swap.c\
		$(MANDATORY_DIR)/ops/rotate/forward/ra.c\
		$(MANDATORY_DIR)/ops/rotate/forward/rb.c\
		$(MANDATORY_DIR)/ops/rotate/forward/rr.c\
		$(MANDATORY_DIR)/ops/rotate/reverse/rra.c\
		$(MANDATORY_DIR)/ops/rotate/reverse/rrb.c\
		$(MANDATORY_DIR)/ops/rotate/reverse/rrr.c\
		$(MANDATORY_DIR)/ops/rotate/rotate.c\
		$(MANDATORY_DIR)/stack_utils/stack_utils.c\
		$(MANDATORY_DIR)/stack_utils/stack_add_utils.c\
		$(MANDATORY_DIR)/stack_utils/stack_remove_utils.c\

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compilar libs

$(LIBFT_LIB):
	make bonus -C $(LIBFT_DIR)

# .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(LIBFT_LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re