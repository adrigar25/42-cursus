CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC = main.c
OBJ = $(SRC:.c=.o)
TARGET = usleep_test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)

fclean: clean

re: fclean all
