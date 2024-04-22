# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:55:22 by joseanto          #+#    #+#              #
#    Updated: 2024/04/19 19:16:24 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ASSISTANT = ./assistant/
COMMANDS = ./commands/
ARGUMENTS = ./argument_management/
FILE =	minishell.c\
	$(ASSISTANT)len.c\
	$(ASSISTANT)ft_strtrim.c\
	$(ASSISTANT)ft_split.c\
	$(ASSISTANT)skip_str.c\
	$(ASSISTANT)build_path.c\
	$(ASSISTANT)copy.c\
	$(ASSISTANT)search.c\
	$(ARGUMENTS)environment_variable.c\
	$(ARGUMENTS)list_operations.c\
	$(COMMANDS)echo.c\
	$(COMMANDS)cd.c\
	$(COMMANDS)pwd.c\
	$(COMMANDS)export.c\
	$(COMMANDS)env.c\
	$(COMMANDS)exit.c\
	$(COMMANDS)exec_program.c
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