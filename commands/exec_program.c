/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:43 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:44 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*build_path(char *str1, char *str2)
{
	char	*str;
	int		i;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	str = malloc((ft_strlen(str1) + ft_strlen(str2) + 2)
			* sizeof(char));
	i = 0;
	while (*str1)
	{
		str[i] = *str1;
		i++;
		str1++;
	}
	str[i] = '/';
	i++;
	while (*str2)
	{
		str[i] = *str2;
		i++;
		str2++;
	}
	str[i] = '\0';
	return (str);
}

char	*tester_path(char **path, char *file)
{
	char		*path_file;
	struct stat	info;

	if (stat(file, &info) == 0)
		return (copy_str(file));
	while (path && *path)
	{
		path_file = build_path(*path, file);
		if (stat(path_file, &info) == 0)
			return (path_file);
		free(path_file);
		path++;
	}
	path_file = malloc(sizeof(char));
	*path_file = '\0';
	return (path_file);
}

void	error_execve(char *path_file, t_str **env_list, char **argv)
{
	struct stat	info;

	if (path_file[0] != '\0' && access(path_file, X_OK) == -1)
		error_message("-minishell: %s: Permissão negada\n",
			path_file, 126, env_list);
	else if (stat(path_file, &info) == 0 && S_ISDIR(info.st_mode))
		error_message("-minishell: %s: É um diretório\n",
			path_file, 126, env_list);
	else if (*argv[0] == '.' && stat(path_file, &info) == -1)
		error_message("-minishell: %s: Arquivo ou diretório inexistente\n",
			*argv, 127, env_list);
	else if (path_file[0] == '\0' && *argv[0] != '.')
		error_message("%s: comando não encontrado\n", *argv, 127, env_list);
	free(path_file);
}

void	exec_program(char **argv, char **env, char *str, t_str **env_list)
{
	pid_t	pid;
	t_str	*variable;
	char	**path;
	char	*path_file;
	int		status;

	path = NULL;
	pid = fork();
	if (pid == 0)
	{
		variable = search_variable_list(env_list, "PATH");
		if (variable)
			path = ft_split(&variable->str[5], ':');
		path_file = tester_path(path, *argv);
		if (path)
			free_split(path);
		execve(path_file, argv, env);
		error_execve(path_file, env_list, argv);
		exit_shell(argv, str, env, env_list);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		variable_status(WEXITSTATUS(status), env_list);
}
