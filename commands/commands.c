/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:33 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:37:11 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief PROCURA UMA ESTRING NO COMECO DE OUTRA LEVANADO EM CONSIDERACAO O FINAL DA COMPARACAO
/// @param s1 STRING A SER COMPARADA
/// @param s2 STRING A SER COMPARADA
/// @return SE AO FINAL DA COMPARACAO TENHA ' ' '	' OU '\0' RETORNA 1 EXEMPLO: "ls", "ls -all" ou "pwd", "pwd"
/// @return CASO NO FINAL DA COMPARACAO TENHA ALGO DIFERENTE RETORNA 0 EXEMPLO: "ls", "ls-all" ou "pwd", "pwdx"
int	compare(char *s1, char *s2)
{
	int	i;

	if (s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	commands(char *str, char **args, char ***argenv, t_str **env_list)
{
	if (declaration_variable(args[0]))
		add_variable(args, *argenv, env_list);
	else if (compare("echo", args[0]))
		echo(args, env_list);
	else if (compare("cd", args[0]))
		cd(str, *argenv, env_list);
	else if (compare("pwd", args[0]))
		pwd(env_list);
	else if (compare("export", args[0]))
		export(args, argenv, env_list);
	else if (compare("unset", args[0]))
		unset(args, env_list, *argenv);
	else if (compare("env", args[0]))
		env(*argenv, env_list);
	else if (compare("exit", args[0]))
		exit_shell(args, str, *argenv, env_list);
	else
		exec_program(args, *argenv, str, env_list);
}
