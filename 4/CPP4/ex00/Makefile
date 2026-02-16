# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 13:45:00 by agarcia           #+#    #+#              #
#    Updated: 2026/02/16 18:47:56 by agarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= animal

CPP			:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98 -I includes

SRC_DIR		:= src
SRCS		:= 	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Animal.cpp \
				$(SRC_DIR)/Dog.cpp \
				$(SRC_DIR)/Cat.cpp \
				$(SRC_DIR)/WrongAnimal.cpp \
				$(SRC_DIR)/WrongCat.cpp
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
