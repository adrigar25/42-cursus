NAME = philo

CC = cc

CFLAGS = -Werror -Wextra -Wall -pthread

DIR = ./philo
OBJDIR = objs

SRCS = $(DIR)/main.c \
		$(DIR)/philo_actions.c \
		$(DIR)/time_utils.c \
		$(DIR)/write_status.c \
		$(DIR)/init.c \

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS)  -o $(DIR)/$(NAME)

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)/$(dir $*)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(DIR)/$(NAME)

re: clean all

.PHONY: all clean fclean re