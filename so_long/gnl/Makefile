# Nombre de la librería
NAME = libgnl.a

# Archivos normales
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# Archivos bonus
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Compilar normal por defecto
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Regla para bonus
bonus:
	$(MAKE) OBJ="$(BONUS_OBJ)" SRC="$(BONUS_SRC)" all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re