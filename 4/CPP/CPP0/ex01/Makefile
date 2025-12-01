# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 14:52:59 by agarcia           #+#    #+#              #
#    Updated: 2025/11/10 14:52:59 by agarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= phonebook

CPP		:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS		:= main.cpp \
		   PhoneBook.cpp \
		   Contact.cpp
OBJS_DIR	:= objs
OBJS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re