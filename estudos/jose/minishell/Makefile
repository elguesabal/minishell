# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:55:22 by joseanto          #+#    #+#              #
#    Updated: 2024/03/26 09:59:05 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	minishell.c
CC = cc
FLAGS = -Wall -Wextra -Werror -o
READLINE = -lreadline
NAME = minishell
RM = rm

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(FILE) $(READLINE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re