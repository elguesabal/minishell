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

// ./assistant/ft_strlen.c
size_t	ft_strlen(const char *str); // NAO USANDO POR ENQUANTO

// ./assistant/ft_strtrim
char	*ft_strtrim(char const *s1, char const *set); // NAO USANDO POR ENQUANTO

// ./assistant/ft_split.c
char	**ft_split(char const *s, char c); // NAO USANDO POR ENQUANTO

// ./assistant/skip_str.c
char	*skip_char(char *str);
char	*skip_space(char *str);

// ./commands/echo.c
// int	search_operator(char *str, char *operator) // TEMPORARIO // NAO USANDO POR ENQUANTO
int	search_operator(char **argv, char *operator); // TEMPORARIO
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
void    exec_program(char **argv);





// ./minishell.c
int	compare(char *s1, char *s2);    // TEMPORARIO



#endif