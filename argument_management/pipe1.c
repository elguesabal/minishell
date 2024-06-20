/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:24 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:11:48 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_pipe(char **argv)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

int	**init_fd(int n_process)
{
	int	**fd;
	int	i;

	fd = malloc(n_process * sizeof(int *));
	if (fd == NULL)
		return (NULL);
	i = 0;
	while (i < n_process)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (fd[i] == NULL)
			return (NULL);
		pipe(fd[i]);
		i++;
	}
	return (fd);
}

void	close_fds(int **fd, int n_process)
{
	int	i;

	i = 0;
	while (i < n_process)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] && args[i][0] != '|')
		i++;
	return (i);
}

void	redirection_pipe(int current_process, int **fd, int n_process)
{
	if (current_process > 0)
		dup2(fd[current_process - 1][0], STDIN_FILENO);
	if (current_process < n_process)
		dup2(fd[current_process][1], STDOUT_FILENO);
	close_fds(fd, n_process);
}
