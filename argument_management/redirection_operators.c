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


void	redirection_operators(char *str, char **argv, char ***argenv, t_str **env_list)
{
	int	process;
	int	operator;

	process = -1;
	while (argv[process])
	{
		process++;
//   |   -->  1
//   >   -->  2
//   >>  -->  3
//   <   -->  4
//   <<  -->  5
		operator = search_next_operator(&argv[process]);

printf("process: %d\n", process);
printf("operator: %d\n\n", operator);

		if (operator == 1)
			command_pipe(str, &argv[process], argenv, env_list);
		// else if (search_operator(argv, '>')) // ESSES AINDA VAO EXISTIR
		// 	command_bigger_then();
		// else if (search_operator(argv, '<'))
		// 	command_less_then();



// INTERPRETA O REDIRECIONADOR
	// > REDIRECIONA
	// | ABRE O PROCESSO

// EXECUTA O PRIMEIRO PROGRAMA
	// SE FOR ">" JA FOI CRIADO O ARQUIVO E SALVADO (NAO FAZ NADA NESSE MOMENTO)
	// SE FOR "|" ESPERA O PROCESSO TERMINAR COM waitpid() REPETE O PROCESSO COM O SEGUNDO PROGRAMA

// ENCERRA O REDIRECIONAMENTO
	// SE FOR ">" NORMALIZA O FD
	// SE FOR "|" ESPERA O SEGUNDO PROCESSO TERMINAR



		while (argv[process] && argv[process][0] != '|' && argv[process][0] != '>' && argv[process][0] != '<')
		{
			process++;
		}
	}

printf("process final: %d\n", process);
}
