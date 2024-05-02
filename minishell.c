/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/05/02 08:44:10 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	main(int argc, char **argv, char **argenv)
{
	char	*str;
	char	**args;
	t_str	*env_list;

	(void)argc;
	(void)argv;

	env_list = NULL;
	creat_list(&env_list, argenv);
	argenv = array_to_list(&env_list);

	while (1)
	{
		str = readline("minishell: ");
// printf("teste :%d\n", (*str == '\0')); // CASO PRESSIONE ENTER SEM DIGITAR NADA NO SHELL *str == 0

// iuiih();
		swap_space(str);
		// if (aspas)
			// swap_tab();
		args = ft_split(str, ' ');

		argument_management(args, &env_list);

		if (declaration_variable(args[0]))
			add_variable(args, argenv, &env_list);
		else if (compare("echo", str))
			echo(args);
		else if (compare("cd", str))
			cd(str, argenv, &env_list);
		else if (compare("pwd", str))
			pwd();
		else if (compare("export", str))
			export(args, &argenv, &env_list);
		else if (compare("unset", str))
			unset(args, &env_list, argenv);
		else if (compare("env", str))
			env(argenv);
		else if (compare("exit", str))
			exit_shell(args, str, argenv, &env_list);
		else
			exec_program(args, argenv, str, &env_list);
		free(str);
		free_split(args);
	}
	// return (0); // SE O PROGRAMA SAI TERMINA SEMPRE COM A FUNCAO exit() E NECESSARIO O RETURN?
}












// EU IMPLEMENTEI O REDIRECIONAMENTO DE SAIDA NO echo ENTAO ATE EU FIZER ISSO FORA DO echo DEIXAREI ISSO COMENTADO PRA USAR DPS
// void	echo(char **argv)	// AINDA TESTANDO ALGUMAS COISAS ENTAO IGNORAR POR ENQUANTO ESSA FUNCAO
// {
// // printf("teste: %d\n", search_operator(argv, ">>"));


// 	char	flag;
// 	int	output;
// 	int	fd;
// 	int	new_stdout;

// 	flag = '\n';
// 	output = 1;
// 	// fd = ?? // TALVEZ EU DEVA INICIAR O fd PARA USAR close EM QUALQUER SITUACAO
// 	new_stdout = 1;	// TALVEZ EU DEVA INICIAR COM 1 PRA USAR A FUNCAO dup2 EM QUALQUER SITUACAO

// 	if (argv[1][0] == '-' && argv[1][1] == 'n')
// 	{
// 		flag = '\0';
// 		output++;
// 	}

// 	if (search_operator(argv, ">>"))	// >>	// DEVO FAZER ISSO FORA DA FUNCAO
// 	{
// 		fd = open(argv[output + 2], O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
// 		new_stdout = dup(STDOUT_FILENO);
// 		dup2(fd, STDOUT_FILENO);
// 	}
// 	else if (search_operator(argv, ">"))	// >
// 	{}
// 	else if (0)	// <
// 	{}
// 	else if (0)	// <<
// 	{}
// 	// else
// 	// 	printf("%s%c", command, flag);



// 	printf("%s%c", argv[output], flag);


// 	// printf("teste com dup2: %d\n", dup2(new_stdout, STDOUT_FILENO));
// 	dup2(new_stdout, STDOUT_FILENO);
// 	// NAO USEI A FUNCAO close PARA FECAR NENHUM open
// }
