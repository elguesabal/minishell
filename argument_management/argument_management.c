#include "../minishell.h"

// /// @brief CONTA O TAMANHO QUE O ARRAY DEVERIA TER CASO OS OPERADORES DE REDIRECIONAMENTO ESTIVESSEM SEPARADOS
// /// @param args RECEBE UM PONTEIRO DE ARRAY DE STRINGS COM ARGUMENTOS
// /// @return RETORNA A QUANTIDADE DE STRINGS QUE DEVERIA TER
// int	len_args_operators(char	**args) // AGR ESTOU SEPARANDO OS ARGUMENTOS ANTES DE USAR ft_split()
// {
// 	int	i;
// 	int	j;
// 	int	arguments;

// 	i = 0;
// 	arguments = 0;
// 	while (args[i])
// 	{
// 		if (args[i][0] != '|' && args[i][0] != '>' && args[i][0] != '<')
// 			arguments++;

// 		j = 0;
// 		while (args[i][j])
// 		{
// 			if (((args[i][j] == '>' && args[i][j + 1] == '>') || (args[i][j] == '<' && args[i][j + 1] == '<')) && args[i][j + 2])
// 			{
// 				arguments += 2;
// 				j++;
// 			}
// 			else if ((args[i][j] == '>' && args[i][j + 1] == '>') || (args[i][j] == '<' && args[i][j + 1] == '<'))
// 			{
// 				arguments++;
// 				j++;
// 			}
// 			else if ((args[i][j] == '|' || args[i][j] == '>' || args[i][j] == '<') && args[i][j + 1])
// 			{
// 				arguments += 2;
// 			}
// 			else if (args[i][j] == '|' || args[i][j] == '>' || args[i][j] == '<')
// 			{
// 				arguments++;
// 			}

// 			j++;
// 		}

// 		i++;
// 	}
// 	return (arguments);
// }


/// @brief CONTA O TAMANHO QUE A STRING DEVERIA TER CASO OS OPERADORES DE REDIRECIONAMENTO ESTIVESSEM SEPARADOS
/// @param str RECEBE UM PONTEIRO DE ARRAY DE CHAR COM ARGUMENTOS
/// @return RETORNA O TAMANHO DA STRING QUE DEVERIA TER
int	len_separating_operators(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '	' && *str != '|' && *str != '>' && *str != '<' && (*(str + 1) == '|' || *(str + 1) == '>' || *(str + 1) == '<'))
		{
			len++;
		}
		else if ((*str == '|' || *str == '>' || *str == '<') && *(str + 1) != ' ' && *(str + 1) != '	' && *(str + 1) != '|' && *(str + 1) != '>' && *(str + 1) != '<' && *(str + 1) != '\0')
		{
			len++;
		}

		len++;
		str++;
	}
	return (len);
}

/// @brief ALOCA UM NOVO ENDERECO DE MEMORIA E SEPARA OS OPERADORES DE REDIRECIONAMENTO DE OUTROS ARGUMENTOS POR UM ESPACO (USA free() NO ANTIGO ENDERECO DE MEMORIA)
/// @param str RECEBE UM PONTEIRO DE CHAR COM ARGUMENTOS
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM OS AGUMENTOS SEPARADOS
void	separate_redirection_operators(char **str)
{
	char	*copy_str;
	int	i;
	int j;

	if (!(search_char(*str, '|') || search_char(*str, '>') || search_char(*str, '<')))
		return ;
	copy_str = malloc((len_separating_operators(*str) + 1) * sizeof(char));
	if (copy_str == NULL)
		return ;
	i = 0;
	j = 0;
	while (str[0][i])
	{
		copy_str[i + j] = str[0][i];
		if (str[0][i] != ' ' && str[0][i] != '	' && str[0][i] != '|' && str[0][i] != '>' && str[0][i] != '<' && (str[0][i + 1] == '|' || str[0][i + 1] == '>' || str[0][i + 1] == '<'))
		{
			j++;
			copy_str[i + j] = ' ';
			// copy_str[i + ++j] = ' '; // ISSO PODE REDUZIR LINHAS
		}
		else if ((str[0][i] == '|' || str[0][i] == '>' || str[0][i] == '<') && str[0][i + 1] != ' ' && str[0][i + 1] != '	' && str[0][i + 1] != '|' && str[0][i + 1] != '>' && str[0][i + 1] != '<' && str[0][i + 1] != '\0')
		{
			j++;
			copy_str[i + j] = ' ';
		}
		i++;
	}
	copy_str[i + j] = '\0';
	free(*str);
	*str = copy_str;
// printf("*str: %s\n", *str);
}

void	argument_management(char ***argv, t_str **env_list)
{
	int	i;
	// char	**copy_argv;

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

						// ACHO Q VOU FAZER ISSO ANTES DE USAR split()
// 	if (strstrlen(*argv) != len_args_operators(*argv))
// 	{
// 		copy_argv = *argv;
// 		*argv = malloc(len_args_operators(*argv) * sizeof(char *));
// 		if (*argv == NULL)
// 		{
// 			*argv = copy_argv;
// 			return ;
// 		}

// free(*argv); // TEMPORARIO PARA TESTAR SEM ERROS NO VALGRIND
// *argv = copy_argv;


// 		// free(copy_argv); // DESCOMENTAR QUANDO TERMINAR DE ALOCAR MEMORIA CORRETAMENTE E ADICIONAR CONTEUDO
// printf("alloquei memoria\n");
// 	}
						// ACHO Q VOU FAZER ISSO ANTES DE USAR split()


	// if (search_pipe(argv)) // SE MUDOU PARA redirection_operators.c
	// 	command_pipe(argv);

}
