/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:30 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:09:57 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief NOVO CAMINHO ATUAL DA VARIAVEL DE AMBIENTE PWD
/// @param pwd CAMINHO ATUALIZADO
/// @return RETORNA A STRING COM VARIAVEL DE AMBIENTE PRONTA PARA SER ATUALIZADA
char	*new_pwd(char *pwd)
{
	char	*variable;
	int		i;

	variable = malloc((ft_strlen(pwd) + 5) * sizeof(char));
	if (variable == NULL)
		return (NULL);
	variable[0] = 'P';
	variable[1] = 'W';
	variable[2] = 'D';
	variable[3] = '=';
	i = 4;
	while (*pwd)
	{
		variable[i] = *pwd;
		pwd++;
		i++;
	}
	variable[i] = '\0';
	return (variable);
}

void	cd(char *command, char **env, t_str **env_list)
{
	struct stat	info;
	char		*argv[2];

	variable_status(0, env_list);
	command = skip_char(command);
	command = skip_space(command);
	if (stat(command, &info) == 0 && S_ISDIR(info.st_mode) && access(command, X_OK) == -1)
		error_message("-minishel: cd: %s: Permissão negada\n", command, 1, env_list);
	else if (stat(command, &info) == 0 && !S_ISDIR(info.st_mode))
		error_message("-minishell: cd: %s: Não é um diretório\n", command, 1, env_list);
	else if (chdir(command) == -1)
		error_message("-minishell: cd: %s: Arquivo ou diretório inexistente\n", command, 1, env_list);
	argv[0] = new_pwd(getcwd(NULL, 0));
	argv[1] = NULL;
	add_variable(argv, env, env_list);
	free(argv[0]);
}
