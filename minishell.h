/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:10:16 by joseanto          #+#    #+#             */
/*   Updated: 2024/04/09 18:19:09 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>


typedef struct s_token
{
    int command;
    // int arguments;
    int dollar_sign;
    int single_quotes;
    int double_quotes;
    int bigger_then;
    int two_greater_than;
    int pipe;
}   t_token;


// ./assistant/ft_strlen.c
size_t	ft_strlen(const char *str);
int	strlen_char(char *str, char c);

// ./assistant/ft_strtrim
char	*ft_strtrim(char const *s1, char const *set);

// ./assistant/ft_split.c
char	**ft_split(char const *s, char c);

// ./assistant/skip_str.c
char	*skip_char(char *str);
char	*skip_space(char *str);

// ./assistant/concatenate.c
char    *build_path(char *str1, char *str2);

// ./commands/echo.c
// int	search_operator(char *str, char *operator) // TEMPORARIO // NAO USANDO POR ENQUANTO
// int	search_operator(char **argv, char *operator); // TEMPORARIO // NAO USANDO POR ENQUANTO
void	echo(char **argv);

// ./commands/cd.c
void	cd(char *command);

// ./commands/pwd.c
void	pwd(void);

// ./commands/export.c

// ./commands/unset.c

// ./commands/env.c

// ./commands/exit.c
void	free_split(char **argv);    // TEMPORARIO
void	exit_shell(char **argv, char *str);

// ./commands/exec_program.c
void    exec_program(char **argv, char **env, char *str);




// ./minishell.c
char    *tester_path(char **path, char *file);
char	*expand_variable(char *free_str, char *new_str);
void	analyze(char **argv, t_token *info);
int	compare(char *s1, char *s2);    // TEMPORARIO



#endif