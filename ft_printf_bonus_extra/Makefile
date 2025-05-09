NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_puthex.c \
	ft_putptr.c

BONUS_SRCS = ./bonus/ft_printf_bonus.c \
	./bonus/ft_putchar_bonus.c \
	./bonus/ft_putstr_bonus.c \
	./bonus/ft_putnbr_bonus.c \
	./bonus/ft_putunbr_bonus.c \
	./bonus/ft_puthex_bonus.c \
	./bonus/ft_putptr_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:
	@make OBJ_FILES="$(BONUS_OBJS)" build_bonus

build_bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus build_bonus