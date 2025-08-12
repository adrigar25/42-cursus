# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: agarcia <agarcia@student.42.fr>			+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2025/07/31 12:19:11 by agarcia		   #+#	#+#			  #
#	Updated: 2025/08/11 22:13:02 by agarcia		  ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

LIBFT_DIR = ./libs/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

GNL_DIR = ./libs/get_next_line
GNL_LIB = $(GNL_DIR)/libgnl.a

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(GNL_DIR)

MANDATORY_DIR = ./src/mandatory
BONUS_DIR = ./src/bonus
OBJDIR = objs

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
	$(MANDATORY_DIR)/ops/rotate/rotate.c

BONUS_SRCS = \
	$(BONUS_DIR)/checker_bonus.c \
	$(BONUS_DIR)/checker_utils_bonus.c \
	$(BONUS_DIR)/ops/push_bonus.c \
	$(BONUS_DIR)/ops/swap_bonus.c \
	$(BONUS_DIR)/ops/rotate/rotate_bonus.c \
	$(BONUS_DIR)/ops/rotate/forward/ra_bonus.c \
	$(BONUS_DIR)/ops/rotate/forward/rb_bonus.c \
	$(BONUS_DIR)/ops/rotate/forward/rr_bonus.c \
	$(BONUS_DIR)/ops/rotate/reverse/rra_bonus.c \
	$(BONUS_DIR)/ops/rotate/reverse/rrb_bonus.c \
	$(BONUS_DIR)/ops/rotate/reverse/rrr_bonus.c \
	$(BONUS_DIR)/utils/stack_add_utils_bonus.c \
	$(BONUS_DIR)/utils/stack_remove_utils_bonus.c \
	$(BONUS_DIR)/utils/stack_utils_bonus.c \
	$(BONUS_DIR)/utils/validation_utils_bonus.c \
	$(BONUS_DIR)/utils/utils_bonus.c \
	$(GNL_DIR)/get_next_line.c \

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(LIBFT_LIB) $(GNL_LIB) $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -o $(BONUS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)/$(dir $*)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(LIBFT_LIB)
	rm -f $(NAME)
	rm -f $(BONUS)
	rm -f $(GNL_DIR)/lingnl.a

re: fclean all

.PHONY: all clean fclean re bonus