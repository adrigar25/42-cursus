# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 14:53:15 by agarcia           #+#    #+#              #
#    Updated: 2026/01/20 14:41:19 by agarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= form

CPP		:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC_DIR		:= src
INC_DIR		:= include
OBJS_DIR	:= objs

SRCS		:= Bureaucrat.cpp \
			   Form.cpp \
			   main.cpp
OBJS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re