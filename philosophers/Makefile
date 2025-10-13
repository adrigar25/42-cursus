NAME = philo
BONUS_NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC_MAND = philosophers
OBJDIR_MAND = objs/philosophers

SRCS_MAND = $(wildcard $(SRC_MAND)/*.c)

OBJS_MAND = $(SRCS_MAND:$(SRC_MAND)/%.c=$(OBJDIR_MAND)/%.o)

all: $(NAME)

$(NAME): $(OBJS_MAND)
	$(CC) $(CFLAGS) $(OBJS_MAND) -o $(NAME)


$(OBJDIR_MAND)/%.o: $(SRC_MAND)/%.c
	mkdir -p $(OBJDIR_MAND)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -rf $(OBJDIR_MAND) 

fclean: clean
	@rm -rf $(NAME)objs

re: fclean all

.PHONY: all  clean fclean re

