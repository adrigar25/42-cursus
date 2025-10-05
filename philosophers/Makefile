NAME = philo
BONUS_NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC_MAND = src/mandatory/philo
SRC_BONUS = src/bonus/philo
OBJDIR_MAND = objs/mandatory
OBJDIR_BONUS = objs/bonus

SRCS_MAND = $(wildcard $(SRC_MAND)/*.c)
SRCS_BONUS = $(wildcard $(SRC_BONUS)/*.c)

OBJS_MAND = $(SRCS_MAND:$(SRC_MAND)/%.c=$(OBJDIR_MAND)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS)/%.c=$(OBJDIR_BONUS)/%.o)

all: $(NAME)

$(NAME): $(OBJS_MAND)
	$(CC) $(CFLAGS) $(OBJS_MAND) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

$(OBJDIR_MAND)/%.o: $(SRC_MAND)/%.c
	mkdir -p $(OBJDIR_MAND)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_BONUS)/%.o: $(SRC_BONUS)/%.c
	mkdir -p $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR_MAND) $(OBJDIR_BONUS)

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME) objs

re: fclean all

.PHONY: all bonus clean fclean re

