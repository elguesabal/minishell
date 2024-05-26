#include "../minishell.h"

/// @brief CONTA O TAMANHO QUE O ARRAY DEVERIA TER CASO OS OPERADORES DE REDIRECIONAMENTO ESTIVESSEM SEPARADOS
/// @param args RECEBE UM PONTEIRO DE ARRAY DE STRINGS COM ARGUMENTOS
/// @return RETORNA A QUANTIDADE DE STRINGS QUE DEVERIA TER
int	len_args_operators(char	**args)
{
	int	i;
	int	j;
	int	arguments;

	i = 0;
	arguments = 0;
	while (args[i])
	{
		if (args[i][0] != '|' && args[i][0] != '>' && args[i][0] != '<')
			arguments++;

		j = 0;
		while (args[i][j])
		{
			if (((args[i][j] == '>' && args[i][j + 1] == '>') || (args[i][j] == '<' && args[i][j + 1] == '<')) && args[i][j + 2])
			{
				arguments += 2;
				j++;
			}
			else if ((args[i][j] == '>' && args[i][j + 1] == '>') || (args[i][j] == '<' && args[i][j + 1] == '<'))
			{
				arguments++;
				j++;
			}
			else if ((args[i][j] == '|' || args[i][j] == '>' || args[i][j] == '<') && args[i][j + 1])
			{
				arguments += 2;
			}
			else if (args[i][j] == '|' || args[i][j] == '>' || args[i][j] == '<')
			{
				arguments++;
			}

			j++;
		}

		i++;
	}
	return (arguments);
}

void	argument_management(char ***argv, t_str **env_list)
{
	int	i;
	char	**copy_argv;

	i = 0;
	while (argv[0][i])
	{
		/* '' */
		/* "" */
		/* $ */ argv[0][i] = environment_variable(argv[0][i], env_list);
		/* > */
		/* >> */
		/* | */ // VC AGR FDP
		/* < */
		/* << */

		i++;
	}

	if (strstrlen(*argv) != len_args_operators(*argv))
	{
		copy_argv = *argv;
		*argv = malloc(len_args_operators(*argv) * sizeof(char *));
		if (*argv == NULL)
		{
			*argv = copy_argv;
			return ;
		}

free(*argv); // TEMPORARIO PARA TESTAR SEM ERROS NO VALGRIND
*argv = copy_argv;


		// free(copy_argv); // DESCOMENTAR QUANDO TERMINAR DE ALOCAR MEMORIA CORRETAMENTE E ADICIONAR CONTEUDO
printf("alloquei memoria\n");
	}


	// if (search_pipe(argv)) // SE MUDOU PARA redirection_operators.c
	// 	command_pipe(argv);

}
