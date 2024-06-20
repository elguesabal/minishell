/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:13 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:05:14 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	search_dollar_sign(char *str)
{
	while (*str)
	{
		if (*str == '$' && str[1])
			return (1);
		str++;
	}
	return (0);
}

char	*malloc_variable(char *str, t_str **env_list)
{
	char	*copy_new;

	if (str == NULL)
	{
		copy_new = malloc(sizeof(char));
		copy_new = '\0';
		return (copy_new);
	}
	copy_new = malloc((len_all_variable(str, env_list) + 1) * sizeof(char));
	if (copy_new == NULL)
		printf("Error: a funcao malloc() retornou NULL\n");
	return (copy_new);
}

void	swap_variable(t_str **env_list, char **str, char *copy_new, int *i)
{
	t_str	*no;
	char	*variable;

	no = search_variable_list(env_list, &str[0][1]);
	if (no)
	{
		variable = skip_c(no->str, '=') + 1;
		while (*variable)
		{
			copy_new[*i] = *variable;
			variable++;
			(*i)++;
		}
	}
	if (str[0][0] == '$' && str[0][1] == '?')
		(*str)++;
	else
	{
		while (str[0][1] && ((str[0][1] >= '0' && str[0][1] <= '9')
			|| (str[0][1] >= 'A' && str[0][1] <= 'Z')
			|| (str[0][1] >= 'a' && str[0][1] <= 'z') || str[0][1] == '_'))
			(*str)++;
	}
}

char	*expand_variable(char *str, t_str **env_list)
{
	char	*copy_new;
	int		i;

	copy_new = malloc_variable(str, env_list);
	if (copy_new == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str == '$')
			swap_variable(env_list, &str, copy_new, &i);
		else
		{
			i++;
			copy_new[i - 1] = *str;
		}
		str++;
	}
	copy_new[i] = '\0';
	return (copy_new);
}

char	*environment_variable(char *arg, t_str **env_list)
{
	char	*arg_free;
	t_str	*no;
	int		i;

	if (search_dollar_sign(arg))
	{
		no = search_variable_list(env_list, arg + strlen_char(arg, '$') + 1);
		arg_free = arg;
		if (no)
			arg = expand_variable(arg, env_list);
		else
		{
			arg = malloc((strlen_char(arg, '$') + 1) * sizeof(char));
			i = 0;
			while (arg_free[i] && arg_free[i] != '$')
			{
				arg[i] = arg_free[i];
				i++;
			}
			arg[i] = '\0';
		}
		free(arg_free);
	}
	return (arg);
}
