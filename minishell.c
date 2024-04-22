/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/04/19 19:50:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	init_count(t_token *info)
// {
// 	info->command = 0;
// 	// info->arguments = 0;
// 	info->dollar_sign = 0;
// 	info->single_quotes = 0;
// 	info->double_quotes = 0;
// 	info->bigger_then = 0;
// 	info->two_greater_than = 0;
// 	info->pipe = 0;
// }


void	analyze(char **argv)
{
	int	i;

	i = 1; // TEM Q COMECAR A VERIFICAR APARTIR DO SEGUNDO ARGUMENTO PQ O PRIMEIRO E O COMANDO
	while (argv[i])
	{
		// if (search_dollar_sign(argv[i]))
		// {
		// 	info->dollar_sign++;
		// 	argv[i] = expand_variable(argv[i], getenv(&argv[i][strlen_char(argv[i], '$') + 1]));
		// }
		argv[i] = environment_variable(argv[i]);

		i++;
	}
}


int	main(int argc, char **argv, char **argenv)
{
	char	*str;
	char	**args;
	t_str	*env_list;

	(void)argc;
	(void)argv;

	env_list = NULL;
	creat_list(&env_list, argenv);
	// argenv = copy_str_str(argenv); // FUNCAO copy_str_str() SEM USO
	argenv = array_to_list(&env_list); // array_to_list() SUBSTITUI A FUNCAO copy_str_str()


char *teste1 = malloc(sizeof(char) * 5);
teste1[0] = 'A';
teste1[1] = '=';
teste1[2] = 'w';
teste1[3] = 'w';
teste1[4] = '\0';
insert_last(&env_list, teste1);

char *teste2 = malloc(sizeof(char) * 5);
teste2[0] = 'B';
teste2[1] = '=';
teste2[2] = 'z';
teste2[3] = 'z';
teste2[4] = '\0';
insert_last(&env_list, teste2);


// t_str	*assist = env_list;
// while (assist)
// {
// 	printf("aaaa: %s\n", assist->str);
// 	assist = assist->next;
// }

// int	i = 0;
// while (argenv[i])
// {
// 	printf("%s\n", argenv[i]);
// 	i++;
// }


	while (1)
	{
// printf("teste: %s\n", argenv[25]);
		str = readline("minishell: ");
// printf("teste :%d\n", (*str == '\0')); // CASO PRESSIONE ENTER SEM DIGITAR NADA NO SHELL *str == 0
		args = ft_split(str, ' ');


		// AKI EU TENHO Q COMECAR A ANALIZAR OS ARGUMENTOS PASSADOS E VERIFICAR $ > >> |
		// init_count(&info);
		analyze(args);


		if (compare("echo", str))
			echo(args);
		else if (compare("cd", str))
			cd(str);
		else if (compare("pwd", str))
			pwd();
		else if (compare("export", str))
			argenv = export(args, argenv, &env_list);
		else if (compare("unset", str))
		{
			// unset(argenv);
		}
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
