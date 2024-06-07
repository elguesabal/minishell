#include "../minishell.h"

int	len_arguments(char **argv)
{
	int	len;

	len = 0;
	while (argv[len] && argv[len][0] != '|' && argv[len][0] != '>' && argv[len][0] != '<')
		len++;
	return (len);
}

char	**next_process(char **argv)
{
	char	**args_process;
	int	i;

	args_process = malloc((len_arguments(argv) + 1) * sizeof(char *));
	if (args_process == NULL)
		return (NULL);
	i = 0;
	while (argv[i] && argv[i][0] != '|' && argv[i][0] != '>' && argv[i][0] != '<')
	{
		args_process[i] = copy_str(argv[i]);
		i++;
	}
	args_process[i] = NULL;
	return (args_process);
}


void	redirection_operators(char *str, char **argv, char ***argenv, t_str **env_list)
{
(void)str;
(void)argv;
(void)argenv;
(void)env_list;

	int	process;
	int	operator;
	char	**args_process;
	int	new_std[2];

	new_std[0] = dup(STDIN_FILENO);
	new_std[1] = dup(STDOUT_FILENO);
	process = 0;
	while (argv[process])
	{
//   |   -->  1 // NAO ME IMPORTO MAIS COM ESSE VALOR PQ argv NAO RECEBERA MAIS PIPE
//   >   -->  2
//   >>  -->  3
//   <   -->  4
//   <<  -->  5


		args_process = next_process(&argv[process]);
		// free_split(args_process); // USAR ISSO DPS
// int	i = 0;
// while (args_process[i])
// {
// 	printf("args[%d]: %s\n", i, args_process[i]);
// 	i++;
// }
// printf("\n");

// printf("getpid(): %d\n", getpid());
// printf("entrou no redirection_init\n");

		while (argv[process + 1] && argv[process][0] != '|')
		{
			operator = search_next_operator(&argv[process]);
// printf("operator: %d\targv[process]: %s\n", operator, argv[process]);
			if (operator == 2)
				init_bigger_then(&argv[process]);
			else if (operator == 3)
				init_bigger_bigger_than(&argv[process]);
			else if (operator == 4)
				init_less_than(&argv[process]);
			else if (operator == 5)
				init_smaller_smaller_than(&argv[process], env_list);
			else if (operator == 0)
			{
// printf("operator == 0\n");
// printf("argv[%d]: %s\n", process, argv[process]);
			}
			while (argv[process + 1] && argv[process][0] != '|' && argv[process][0] != '>' && argv[process][0] != '<')
				process++;
			process++;
		}

// printf("saiu do redirection_init\n");

		revert_caracter(args_process); // AKI OS METACARACTERES NAO INTERPRETADOS VOLTAM AO NORMAL (APENAS OS CARACTERES DO PROCESSO ATUAL DENTRO DE args_process E O RESTANTE CONTINUA INVERTIDO)

// int	i = 0;
// while (args_process[i])
// {
// 	printf("args_process[i]: %s\n", args_process[i]);
// 	i++;
// }
// printf("operator: %d\n\n", operator);
		if (operator == 2 || operator == 3 || operator == 4 || operator == 5)
			commands(str, args_process, argenv, env_list);



		if (operator == 2 || operator == 3 || operator == 4 || operator == 5)
		{
			dup2(new_std[0], STDIN_FILENO);
			dup2(new_std[1], STDOUT_FILENO);
			unlink(".heredoc"); // TALVEZ SEJA MELHOR APAGAR SO DPS DO LOOP PRINCIPAL JUNTO COM close(new_stdin) E close(new_stdout)
		}

		free_split(args_process);

		while (argv[process + 1])
		{
			process++;
		}
		process++;
	}
	close(new_std[0]);
	close(new_std[1]);
}
