# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:55:22 by joseanto          #+#    #+#              #
#    Updated: 2024/06/14 20:42:46 by joseanto         ###   ########.fr        #
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
	$(ASSISTANT)ft_strchr.c\
	$(ASSISTANT)ft_strjoin.c\
	$(ASSISTANT)get_next_line.c\
	$(ARGUMENTS)environment_variable.c\
	$(ARGUMENTS)argument_management.c\
	$(ARGUMENTS)quotes.c\
	$(ARGUMENTS)pipe1.c\
	$(ARGUMENTS)pipe2.c\
	$(ARGUMENTS)bigger_then.c\
	$(ARGUMENTS)bigger_bigger_than.c\
	$(ARGUMENTS)less_than.c\
	$(ARGUMENTS)smaller_smaller_than.c\
	$(ARGUMENTS)redirection_operators.c\
	$(ARGUMENTS)signal.c\
	$(ARGUMENTS)history.c\
	$(COMMANDS)add_variable.c\
	$(COMMANDS)variable_status.c\
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