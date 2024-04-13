/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/04/09 14:49:27 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// PROCURA UMA ESTRING NO COMECO DE OUTRA LEVANADO EM CONSIDERACAO O FINAL DA COMPARACAO
// SE AO FINAL DA COMPARACAO TENHA ' ' '	' OU '\0' RETORNA 1 EXEMPLO: "ls", "ls -all" ou "pwd", "pwd"
// CASO NO FINAL DA COMPARACAO TENHA ALGO DIFERENTE RETORNA 0 EXEMPLO: "ls", "ls-all" ou "pwd", "pwdx"
int	compare(char *s1, char *s2)	// TRANSFERIR PARA PASTA assistant
{
	int			i;

	if (s2 == NULL)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && s2[i] != ' ' && s2[i] != '	')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}


int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**args;

	(void)argc;
	(void)argv;
	while (1)
	{
		str = readline("minishell: ");
		args = ft_split(str, ' ');


// AKI EU TENHO Q COMECAR A ANALIZAR OS ARGUMENTOS PASSADOS E VERIFICAR $ > >> |


		if (compare("echo", str)) // VERIFICAR COMO O COMANDO echo SE COMPORTA COM A FUNCAO execve()
			echo(args);
		else if (compare("cd", str))
			cd(str);
		else if (compare("pwd", str))
			pwd();
		else if (compare("export", str))
		{}
		else if (compare("unset", str))
		{}
		else if (compare("env", str))
		{}
		else if (compare("exit", str))
			exit_shell(args, str);
		else
			exec_program(args, env, str);
		free(str);
		free_split(args);
	}
	return (0);
}