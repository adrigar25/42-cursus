NAME		:= harlFilter

CPP		:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRC_DIR		:= src
SRCS		:= 		$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Harl.cpp
OBJS_DIR	:= objs
OBJS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR)
	$(CPP) $(CPPFLAGS) -I includes -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re