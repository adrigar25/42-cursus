NAME	:= materia

CPP	 := c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS	:=  src/main.cpp \
			src/AMateria.cpp \
			src/Ice.cpp \
			src/Cure.cpp \
			src/Character.cpp \
			src/MateriaSource.cpp

OBJS_DIR	:= objs
OBJS	:= $(SRCS:src/%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: src/%.cpp | $(OBJS_DIR)
	$(CPP) $(CPPFLAGS) -I includes -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
