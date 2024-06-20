/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:51 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	declaration_and_export(int i, char ***argv, char ***arge, t_str **env)
{
	char	**arg;
	char	*name_variable;

	arg = malloc(2 * sizeof(char *));
	if (*argv == NULL)
		return ;
	arg[0] = argv[0][i];
	arg[1] = NULL;
	add_variable(arg, *arge, env);
	free(arg);
	name_variable = copy_name_variable(argv[0][i]);
	free(argv[0][i]);
	argv[0][i] = name_variable;
}

t_str	*search_variable_list(t_str **no, char *str)
{
	t_str	*assist;

	assist = *no;
	if (str[0] == '?' && str[1] == '\0')
	{
		while (assist)
		{
			if (assist->str[0] == '?' && assist->str[1] == '=')
				return (assist);
			assist = assist->next;
		}
	}
	while (assist)
	{
		if (compare_variable(assist->str, str))
			return (assist);
		assist = assist->next;
	}
	return (NULL);
}

int	search_variable_array(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == str)
			return (1);
		i++;
	}
	return (0);
}

void	export_variable(char ***env, char *str)
{
	char	**new_env;
	int		i;

	new_env = malloc((strstrlen(*env) + 2) * sizeof(char *));
	if (new_env == NULL)
		return ;
	i = 0;
	while (env[0][i])
	{
		new_env[i] = env[0][i];
		i++;
	}
	new_env[i] = str;
	new_env[i + 1] = NULL;
	free(*env);
	*env = new_env;
}

void	export(char **argv, char ***env, t_str **env_list)
{
	int		i;
	t_str	*return_env;

	variable_status(0, env_list);
	i = 1;
	while (argv[i])
	{
		if (declaration_variable(argv[i]))
			declaration_and_export(i, &argv, env, env_list);
		else if (argv[i] == NULL || (argv[i][0] >= '0' && argv[i][0] <= '9')
			|| metacaracterer(argv[i]))
			error_message(
				"-minishell: export: `%s': não é um identificador válido\n",
				argv[i], 1, env_list);
		return_env = search_variable_list(env_list, argv[i]);
		if (return_env && !search_variable_array(*env, return_env->str))
			export_variable(env, return_env->str);
		i++;
	}
}
