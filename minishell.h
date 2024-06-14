/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:10:16 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:39:26 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>



typedef struct s_str
{
	char	*str;
	struct s_str	*next;
}	t_str;


// ./assistant/len.c
size_t	ft_strlen(const char *str);
int 	strstrlen(char **array_ptr);
int		strlen_char(char *str, char c);
int		listlen(t_str *no);
int		len_all_variable(char *str, t_str **env_list);

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

// ./assistant/search.c
int		compare_variable(char *s1, char *s2);
int		search_char(char *str, char c);
int		search_operator(char **argv, char operator);
int		search_next_operator(char **argv);
int		compare_str(char *s1, char *s2);

// ./assistant/list_operations.c
void	insert_last(t_str **no, char *str);
void	creat_list(t_str **no, char **array_str);
char	**array_to_list(t_str **no);
void	free_list(t_str **no);

// ./assistant/ft_itoa.c
char	*ft_itoa(int n);

// ./assistant/ft_atoi.c
int		ft_atoi(const char *str);

// ./assistant/error_message.c
void	error_message(char *message, char *arg, int status, t_str **env_list);

// ./assistant/ft_strchr.c
char	*ft_strchr(char *s, int c);

// ./assistant/ft_strjoin.c
char	*ft_strjoin(char *rest_line, char *buffer);

// ./assistant/get_next_line.c
char	*get_line(char *rest_line);
char	*new_line(char *rest_line);
char	*read_rest_line(int fd, char *rest_line);
char	*get_next_line(int fd);



// ./argument management/argument_management.c
int		len_separating_operators(char *str);
void	separate_redirection_operators(char **str);
void	new_args(char **str, char **copy_str);
int		argument_management(char **str, char ***argv, t_str **env_list);

// ./argument management/environment_variable.c
int		search_dollar_sign(char *str);
char	*malloc_variable(char *str, t_str **env_list);
void	swap_variable(t_str **env_list, char **str, char *copy_new, int *i);
char	*expand_variable(char *str, t_str **env_list);
char	*environment_variable(char *arg, t_str **env_list);

// ./argument management/quotes.c
void	swap_tab(char **args);
int 	closing_quotes(char *str, char quotes);
void	swap_caracter(char *c, int single_quotes, int double_quotes);
void	quotes(char *str);
void	remove_quotes(char *str);
void	revert_caracter(char **args);

// ./argument management/redirection_operators.c
int		len_arguments(char **argv);
char	**next_process(char **argv);
char	**init_redirection(char **argv, int *process, int *operator, t_str **env_list);
void	finish_redirection(int operator, int *new_std, char **args_process);
void	redirection_operators(char *str, char **argv, char ***argenv, t_str **env_list);

// ./argument management/pipe1.c
int		count_pipe(char **argv);
int		**init_fd(int n_process);
void	close_fds(int **fd, int n_process);
int		count_args(char **args);
void	redirection_pipe(int current_process, int **fd, int n_process);

// ./argument management/pipe1.c
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

// ./argument management/history.c
void	init_history(void);
void	new_history(char *str);



// ./commands/add_variable.c
int		metacaracterer(char *str);
int		declaration_variable(char *str);
char	*copy_name_variable(char *str);
void	swap_variable_array(char *old_variable, char *new_variable, char **env);
void	add_variable(char **argv, char **env, t_str **env_list);

// ./commands/variable_status.c
void	update_status(t_str **no, char *str);
void	variable_status(int status, t_str **env_list);

// ./commands/echo.c
void	echo(char **argv, t_str **env_list);

// ./commands/cd.c
char	*new_pwd(char *pwd);
void	cd(char *command, char **env, t_str **env_list);

// ./commands/pwd.c
void	pwd(t_str **env_list);

// ./commands/export.c
void	declaration_and_export(int i, char ***argv, char ***env, t_str **env_list);
t_str	*search_variable_list(t_str **no, char *str);
int		search_variable_array(char **env, char *str);
void	export_variable(char ***env, char *str);
void	export(char **argv, char ***env, t_str **env_list);

// ./commands/unset.c
void	remove_variable_array(char **env, char *str);
void	remove_variable_list(t_str **no, char *str);
void 	unset(char **argv, t_str **env_list, char **env);

// ./commands/env.c
void	env(char **env, t_str **env_list);

// ./commands/exit.c
void	free_split(char **argv);
void	exit_shell(char **argv, char *str, char **env, t_str **env_list);

// ./commands/exec_program.c
char	*build_path(char *str1, char *str2);
char	*tester_path(char **path, char *file);
void	error_execve(char *path_file, t_str **env_list, char **argv);
void	exec_program(char **argv, char **env, char *str, t_str **env_list);

// ./commands/commands.c
int		compare(char *s1, char *s2);
void	commands(char *str, char **args, char ***argenv, t_str **env_list);



// ./minishell.c
void	init_shell(t_str **env_list, char ***argenv);
void	execute_command(char *str, char **args, char ***argenv, t_str **env_list);



#endif