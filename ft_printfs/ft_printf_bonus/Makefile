NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_puthex.c \
	ft_putptr.c

BONUS_SRCS = ft_printf_bonus.c \
	handler_hex.c \
	handler_nbr.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_puthex.c \
	ft_putptr.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus