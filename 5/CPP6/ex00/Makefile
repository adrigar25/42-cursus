NAME = convert

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -Iincludes

SRC_DIR = src
OBJS_DIR = objs
INCLUDES_DIR = ./includes

SRCS = 	ScalarConverter.cpp \
		main.cpp

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p objs 

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJS_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 