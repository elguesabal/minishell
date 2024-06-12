/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/04 19:16:25 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void check_operator(char **arg)
{
    int i;

i = 0;
while (arg[i] && arg[i + 1] != NULL)
{
	if (arg[i][0] == '|')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '>')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '<')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	i++;
}
	if (arg[i][0] == '|' && (arg[i][1] == '>' || arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '>' && (arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '<' && (arg[i][1] == '|' || arg[i][1] == '>'))
		printf("syntax error near '%c'\n", arg[i][0]);
}


void	init_shell(t_str **env_list, char ***argenv)
{
	*env_list = NULL;
	creat_list(env_list, *argenv);
	*argenv = array_to_list(env_list);
	insert_last(env_list, copy_str("?=0"));
}

/// @brief EXECUTA OS COMANDOS DE ACORDO OS OPERADORES DE REDIRECIONAMENTO
/// @param str STRING RECEBIDA POR readline()
/// @param args ARGUMENTOS QUE FORAM ORGANIZADOS PELA FUNCAO ft_split() E INTERPRETADOS POR argument_management()
/// @param argenv VARIAVEIS DE AMBIENTE EXPORTADAS
/// @param env_list TODAS AS VARIAVEIS DE AMBIENTE
void	execute_command(char *str, char **args, char ***argenv, t_str **env_list)
{
	if (search_operator(args, '|'))
		command_pipe(str, args, argenv, env_list);
	else if (search_operator(args, '>') || search_operator(args, '<'))
		redirection_operators(str, args, argenv, env_list);
	else
	{
		revert_caracter(args);
		commands(str, args, argenv, env_list);
	}
}

int	main(int argc, char **argv, char **argenv)
{
	char	*str;
	char	**args;
	t_str	*env_list; 

	(void)argc;
	(void)argv;
	init_shell(&env_list, &argenv);
	while (1)
	{
		str = readline("minishell: ");
// printf("testando ctrl+d\n");
		add_history(str);

		if (*str && argument_management(&str, &args, &env_list) == 0)
			execute_command(str, args, &argenv, &env_list);

		if (*str)
		{
			free(str);
			free_split(args);
		}
	}
}
