/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:56 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:57 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_variable_array(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (compare_variable(env[i], str))
		{
			while (env[i])
			{
				env[i] = env[i + 1];
				i++;
			}
		}
		else
			i++;
	}
}

void	remove_variable_list(t_str **no, char *str)
{
	t_str	*assist;
	t_str	*previous;

	assist = *no;
	previous = NULL;
	while (assist)
	{
		if (compare_variable(assist->str, str))
		{
			if (previous)
				previous->next = assist->next;
			else
				*no = assist->next;
			free(assist->str);
			free(assist);
			return ;
		}
		previous = assist;
		assist = assist->next;
	}
}

void	unset(char **argv, t_str **env_list, char **env)
{
	variable_status(0, env_list);
	while (*argv)
	{
		remove_variable_array(env, *argv);
		remove_variable_list(env_list, *argv);
		argv++;
	}
}
