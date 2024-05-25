# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:55:22 by joseanto          #+#    #+#              #
#    Updated: 2024/05/02 08:37:25 by joseanto         ###   ########.fr        #
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
	$(ASSISTANT)copy.c\
	$(ASSISTANT)search.c\
	$(ASSISTANT)list_operations.c\
	$(ASSISTANT)ft_itoa.c\
	$(ASSISTANT)ft_atoi.c\
	$(ASSISTANT)error_message.c\
	$(ARGUMENTS)environment_variable.c\
	$(ARGUMENTS)argument_management.c\
	$(ARGUMENTS)quotes.c\
	$(ARGUMENTS)pipe.c\
	$(ARGUMENTS)redirection_operators.c\
	$(COMMANDS)add_variable.c\
	$(COMMANDS)echo.c\
	$(COMMANDS)cd.c\
	$(COMMANDS)pwd.c\
	$(COMMANDS)export.c\
	$(COMMANDS)unset.c\
	$(COMMANDS)env.c\
	$(COMMANDS)exit.c\
	$(COMMANDS)exec_program.c\
	$(COMMANDS)commands.c
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