# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 14:52:29 by agarcia           #+#    #+#              #
#    Updated: 2025/12/31 10:47:58 by agarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Zombie

CPP		:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRC_DIR		:= src
SRCS		:= 	$(SRC_DIR)/main.cpp \
		   		$(SRC_DIR)/Zombie.cpp \
		   		$(SRC_DIR)/newZombie.cpp \
		   		$(SRC_DIR)/randomChump.cpp
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