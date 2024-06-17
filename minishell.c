/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:04:31 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief EXECUTA OS COMANDOS DE ACORDO OS OPERADORES DE REDIRECIONAMENTO
/// @param env_list NO INICIAL QUE CAI CONTER TODAS AS VARIAVEIS DE AMBIENTE
/// @param argenv PONTEIRO QUE VAI CONTER TOADAS AS VARIAVEIS DE AMBIENTE EXPORTADAS
void	init_shell(t_str **env_list, char ***argenv)
{
	init_history();
	*env_list = NULL;
	creat_list(env_list, *argenv);
	*argenv = array_to_list(env_list);
	insert_last(env_list, copy_str("?=0"));
	check_signal();
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

// printf("teste: %d\n", (str == NULL));

// // printf("testando ctrl+d\n");
// // if (*str == '\0')
// // 	write(1, "aaaaa\n", 6);
// if (str == NULL)
// 	write(1, "bbbbb\n", 6);



		new_history(str);
		if (str && argument_management(&str, &args, &env_list) == 0)
			execute_command(str, args, &argenv, &env_list);
		if (str)
		{
			free(str);
			str = NULL;
			free_split(args);
		}
	}
}
