#include "../minishell.h"

/* > */
/* >> */
/* | */
/* < */
/* << */


// int	count_pipe(char **argv)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (argv[i][0] == '|')
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

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
	// int	new_stdin;
	// int new_stdout;
	int	new_std[2];
	// int	pid[10]; // TEMPORARIAMENTE ASSIM MAS O CERTO SERIA MALOCAR O TAMANHO CORRETO DE PROCESSOS FILHOS

	// new_stdin = dup(STDIN_FILENO);
	// new_stdout = dup(STDOUT_FILENO);
	new_std[0] = dup(STDIN_FILENO);
	new_std[1] = dup(STDOUT_FILENO);
	process = 0;
	while (argv[process])
	{
//   |   -->  1
//   >   -->  2
//   >>  -->  3
//   <   -->  4
//   <<  -->  5

		// operator = search_next_operator(&argv[process]);

// printf("process: %d\n", process);
// printf("operator: %d\n\n", operator);
		args_process = next_process(&argv[process]);
// int	i = 0;
// while (args_process[i])
// {
// 	printf("args[%d]: %s\n", i, args_process[i]);
// 	i++;
// }
// printf("\n");
		// free_split(args_process); // USAR ISSO DPS

		// if (operator == 1)
		// 	command_pipe(str, &argv[process], argenv, env_list);
		// else if (search_operator(argv, '>')) // ESSES AINDA VAO EXISTIR
		// 	command_bigger_then();
		// else if (search_operator(argv, '<'))
		// 	command_less_then();


// INTERPRETA O REDIRECIONADOR // cat < list > teste
		// > REDIRECIONA
		// | ABRE O PROCESSO
		while (argv[process + 1] && argv[process][0] != '|')
		{
			operator = search_next_operator(&argv[process]);
			if (operator == 1)
			{
// int	i = 0;
// while (argv[process + i])
// {
// 	printf("&argv[process]: %s\n", argv[process + i]);
// 	i++;
// }
// i = 0;
// while (args_process[i])
// {
// 	printf("args_process: %s\n", args_process[i]);
// 	i++;
// }
				// command_pipe(str, args_process, argenv, env_list);
				// pid[?] = init_pipe();
			}
			else if (operator == 2)
			{
				init_bigger_then(&argv[process]);
			}
			else if (operator == 3)
			{
				init_bigger_bigger_than(&argv[process]);
			}
			else if (operator == 4)
			{
				init_less_than(&argv[process]);
			}
			else if (operator == 5)
			{
				init_smaller_smaller_than(&argv[process], env_list);
			}
			else if (operator == 0)
			{

			}
			while (argv[process + 1] && argv[process][0] != '|' && argv[process][0] != '>' && argv[process][0] != '<')
				process++;
			process++;
		}



		revert_caracter(args_process); // AKI OS METACARACTERES NAO INTERPRETADOS VOLTAM AO NORMAL (APENAS OS CARACTERES DO PROCESSO ATUAL DENTRO DE args_process E O RESTANTE CONTINUA INVERTIDO)

// EXECUTA O PRIMEIRO PROGRAMA
		// SE FOR ">" JA FOI CRIADO O ARQUIVO E SALVADO (NAO FAZ NADA NESSE MOMENTO)
		// SE FOR "|" ESPERA O PROCESSO TERMINAR COM waitpid() REPETE O PROCESSO COM O SEGUNDO PROGRAMA
		// if (operator == 1)
		// {

		// }
		// else if (operator == 2)
		// {
		// 	commands(str, args_process, argenv, env_list);
		// }
		// else if (operator == 3)
		// {
		// 	commands(str, args_process, argenv, env_list);
		// }
		// else if (operator == 4)
		// {
		// 	commands(str, args_process, argenv, env_list);
		// }
		// else if (operator == 5)
		// {
		// 	commands(str, args_process, argenv, env_list);
		// }
		// else if (operator == 0)
		// {

		// }
// int	i = 0;
// while (args_process[i])
// {
// 	printf("args_process[i]: %s\n", args_process[i]);
// 	i++;
// }
// printf("operator: %d\n", operator);
		if (operator == 1 || operator == 2 || operator == 3 || operator == 4 || operator == 5)
		{
			commands(str, args_process, argenv, env_list);
		}



// ENCERRA O REDIRECIONAMENTO
		// SE FOR ">" NORMALIZA O FD
		// SE FOR "|" ESPERA O SEGUNDO PROCESSO TERMINAR
		// if (operator == 1)
		// {

		// }
		// else if (operator == 2)
		// {
		// 	finish_bigger_then(new_stdout);
		// }
		// else if (operator == 3)
		// {
		// 	finish_bigger_bigger_than(new_stdout);
		// }
		// else if (operator == 4)
		// {
		// 	finish_less_than(new_stdin);
		// }
		// else if (operator == 5)
		// {
		// 	finish_smaller_smaller_than(new_stdin);
		// }
		// else if (operator == 0)
		// {

		// }
		if (operator == 2 || operator == 3 || operator == 4 || operator == 5)
		{
			// dup2(new_stdin, STDIN_FILENO);
			dup2(new_std[0], STDIN_FILENO);
			// dup2(new_stdout, STDOUT_FILENO);
			dup2(new_std[1], STDOUT_FILENO);
			unlink(".heredoc"); // TALVEZ SEJA MELHOR APAGAR SO DPS DO LOOP PRINCIPAL JUNTO COM close(new_stdin) E close(new_stdout)
		}



		free_split(args_process);

		while (argv[process + 1] && argv[process][0] != '|')
		{
			process++;
		}
		process++;
	}
	close(new_std[0]);
	close(new_std[1]);
// exit(0);
// printf("teste\n");
// printf("process final: %d\n", process);
}
