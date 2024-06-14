/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:48 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:49 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief LIBERA A MEMORIA DE UM PONTEIRO PARA PONTEIRO
/// @param ptr PONTEIRO PARA PONTEIRO A SER LIBERADO
void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	exit_shell(char **argv, char *str, char **env, t_str **env_list)
{
	int	status;

	if (str)
	{
		free(str);
		str = NULL;
	}
	if (argv)
	{
		free_split(argv);
		argv = NULL;
	}
	free(env);
	status = ft_atoi(search_variable_list(env_list, "?")->str + 2);
	free_list(env_list);
	exit(status);
}
