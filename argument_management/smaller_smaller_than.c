/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_smaller_than.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:39 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:05:40 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_smaller_smaller_than(char **args, t_str **env_list)
{
	int		fd;
	char	*line;

	while (*args && args[0][0] != '<')
		args++;
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR);
	while (1)
	{
		line = readline("> ");
		if (compare_str(args[1], line))
			break ;
		line = environment_variable(line, env_list);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	close(fd);
	fd = open(".heredoc", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
}
