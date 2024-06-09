/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:10:16 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/04 19:17:18 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>



// LISTA USADA PARA ARMAZENAR OS INDERECOS DE MEMORIA DAS VARIAVEIS DE AMBIENTE MAS NAO DISPONIBILIZAR PARA SUBPROCESSOS
typedef struct s_str
{
	char	*str;
	struct s_str	*next;
}	t_str;



// ./assistant/len.c
size_t	ft_strlen(const char *str);
int strstrlen(char **array_ptr);
int	strlen_char(char *str, char c);
int	listlen(t_str *no);
int	len_all_variable(char *str, t_str **env_list);

// ./assistant/ft_strtrim
char	*ft_strtrim(char const *s1, char const *set);

// ./assistant/ft_split.c
char	**ft_split(char const *s, char c);

// ./assistant/skip_str.c
char	*skip_char(char *str);
char	*skip_space(char *str);
char	*skip_c(char *str, char c);

// ./assistant/copy.c
char	*copy_str(char *str);
// char	**copy_str_str(char	**ptr);

// ./assistant/search.c
int	compare(char *s1, char *s2);
int	compare_variable(char *s1, char *s2);
int	search_char(char *str, char c);
int	search_operator(char **argv, char operator);
int	search_next_operator(char **argv);
int	compare_str(char *s1, char *s2);

// ./assistant/list_operations.c
void	insert_last(t_str **no, char *str);
void	creat_list(t_str **no, char **array_str);
char	**array_to_list(t_str **no);
void	free_list(t_str **no);

// ./assistant/ft_itoa.c
char	*ft_itoa(int n);
/// @param str STRING QUE SERA PERCORRIDA
/// @param c CHAR Q SERA USADO COMO REFERENCIA PARA PARAR O WHILE
/// @return RETORNA O ENDERECO DO PRIMEIRO ELEMENTO DIFERENTE DO CHAR c
/// @return RETORNA NULL CASO str SEJA NULL
// ./assistant/ft_atoi.c
int	ft_atoi(const char *str);

// ./assistant/error_message.c
void	error_message(char *message, char *arg, int status, t_str **env_list);



// ./argument management/argument_management.c
int	len_separating_operators(char *str);
void	separate_redirection_operators(char **str);
void	argument_management(char ***argv, t_str **env_list);

// ./argument management/environment_variable.c
int	search_dollar_sign(char *str);
char	*malloc_variable(char *str, t_str **env_list);
char	*expand_variable(char *str, t_str **env_list);
char	*environment_variable(char *arg, t_str **env_list);

// ./argument management/quotes.c
// void	swap_space(char *str);
void	swap_tab(char **args);
int closing_quotes(char *str, char quotes);
void    swap_caracter(char *c, int single_quotes, int double_quotes);
void	quotes(char *str);
// char	*remove_quotes(char *str);
void	remove_quotes(char *str);
void	revert_caracter(char **args);

// ./argument management/redirection_operators.c
int	len_arguments(char **argv);
char	**next_process(char **argv);
char	**init_redirection(char **argv, int *process, int *operator, t_str **env_list);
void	finish_redirection(int operator, int *new_std, char **args_process);
void	redirection_operators(char *str, char **argv, char ***argenv, t_str **env_list);

// ./argument management/pipe.c
int	count_pipe(char **argv);
int	**init_fd(int n_process);
void	close_fds(int **fd, int n_process);
int	count_args(char **args);
void	redirection_pipe(int current_process, int **fd, int n_process);
char	**args_pipe(char **argv, int process);
void	execute_process(char *str, char **args_process, char ***argenv, t_str **env_list);
void	finish_pipe(int **fd, int n_process, pid_t *pid);
void	command_pipe(char *str, char **argv, char ***argenv, t_str **env_list);

// ./argument management/bigger_then.c
void	init_bigger_then(char **args);

// ./argument management/bigger_then.c
void	init_bigger_bigger_than(char **args);

// ./argument management/less_than.c
void	init_less_than(char **args);

// ./argument management/smaller_smaller_than.c
void	init_smaller_smaller_than(char **args, t_str **env_list);



// ./commands/add_variable.c
int	metacaracterer(char *str);
int	declaration_variable(char *str);
char	*copy_name_variable(char *str);
void	swap_variable_array(char *old_variable, char *new_variable, char **env);
void	add_variable(char **argv, char **env, t_str **env_list);
void	update_status(t_str **no, char *str);
void	variable_status(int status, t_str **env_list);

// ./commands/echo.c
// int	search_operator(char *str, char *operator) // TEMPORARIO // NAO USANDO POR ENQUANTO
// int	search_operator(char **argv, char *operator); // TEMPORARIO // NAO USANDO POR ENQUANTO
void	echo(char **argv, t_str **env_list);

// ./commands/cd.c
char	*new_pwd(char *pwd);
void	cd(char *command, char **env, t_str **env_list); // DESSE MODO O COMANDO FUNCIONA MESMO Q EU ESTEJA ENTRANDO EM UMA PASTA Q CONTENHA ESPACO NO NOME
// void	cd(char **argv);

// ./commands/pwd.c
void	pwd(void);

// ./commands/export.c
t_str	*search_variable_list(t_str **no, char *str);
int	search_variable_array(char **env, char *str);
void	export_variable(char ***env, char *str);
void	export(char **argv, char ***env, t_str **env_list);

// ./commands/unset.c
void	remove_variable_array(char **env, char *str);
void	remove_variable_list(t_str **no, char *str);
void 	unset(char **argv, t_str **env_list, char **env);

// ./commands/env.c
void	env(char **env);

// ./commands/exit.c
void	free_split(char **argv);    // TEMPORARIO
void	exit_shell(char **argv, char *str, char **env, t_str **env_list);

// ./commands/exec_program.c
char    *build_path(char *str1, char *str2);
char    *tester_path(char **path, char *file);
void    exec_program(char **argv, char **env, char *str, t_str **env_list);

// ./commands/commands.c
void	commands(char *str, char **args, char ***argenv, t_str **env_list);



// ./minishell.c



#endif