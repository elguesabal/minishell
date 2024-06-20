/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:28 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:39:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	metacaracterer(char *str)
{
	while (*str && *str != '=')
	{
		if (*str <= '/' || (*str >= ':' && *str <= '@')
			|| (*str >= '[' && *str <= '^') || *str == '`' || *str >= '{')
			return (1);
		str++;
	}
	return (0);
}

int	declaration_variable(char *str)
{
	if (str == NULL || (*str >= '0' && *str <= '9') || metacaracterer(str))
		return (0);
	while (*str)
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

char	*copy_name_variable(char *str)
{
	char	*name;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '=')
		i++;
	name = malloc((i + 1) * sizeof(char));
	if (name == NULL)
		return (NULL);
	name[i] = '\0';
	while (i)
	{
		i--;
		name[i] = str[i];
	}
	return (name);
}

void	swap_variable_array(char *old_variable, char *new_variable, char **env)
{
	int	i;

	if (old_variable == NULL)
		return ;
	i = 0;
	while (env[i])
	{
		if (env[i] == old_variable)
		{
			env[i] = new_variable;
			return ;
		}
		i++;
	}
}

void	add_variable(char **argv, char **env, t_str **env_list)
{
	int		i;
	char	*name_variable;
	char	*new_variable;
	t_str	*no;

	i = 0;
	while (argv[i])
	{
		name_variable = copy_name_variable(argv[i]);
		no = search_variable_list(env_list, name_variable);
		free(name_variable);
		if (no)
		{
			new_variable = copy_str(argv[i]);
			swap_variable_array(no->str, new_variable, env);
			free(no->str);
			no->str = new_variable;
		}
		else
			insert_last(env_list, copy_str(argv[i]));
		i++;
	}
}
