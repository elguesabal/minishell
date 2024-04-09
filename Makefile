# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:55:22 by joseanto          #+#    #+#              #
#    Updated: 2024/04/09 14:20:26 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	$(ASSISTANT)ft_strlen.c\ // NAO USANDO POR ENQUANTO
#	$(ASSISTANT)ft_strtrim.c\ // NAO USANDO POR ENQUANTO
#	$(ASSISTANT)ft_split.c\ // NAO USANDO POR ENQUANTO

ASSISTANT = ./assistant/
COMMANDS = ./commands/
FILE =	minishell.c\
	$(ASSISTANT)skip_str.c\
	$(COMMANDS)echo.c\
	$(COMMANDS)cd.c\
	$(COMMANDS)pwd.c
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