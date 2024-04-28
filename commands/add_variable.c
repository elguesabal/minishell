#include "../minishell.h"

/// @brief TESTA O PRIMEIRO ARGUMENTO PARA VER E UMA DECLARACAO DE AMBIENTE
/// @param str STRING A SER TESTADA
/// @return RETORNA 1 CASO O ARGUMENTO NAO COMECE COM NUMERO OU '=' E NO MEIO DELE TENHA '='
/// @return RETORNA 0 CASO O NAO ATENDA OS REQUISITOS ACIMA
int	declaration_variable(char *str)
{
	if (str == NULL || *str == '=' || (*str >= '0' && *str <= '9'))
		return (0);
	while (*str)
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}


void	add_variable(char **argv, t_str **env_list)
{
	int	i;
	t_str	*variable;

	i = 0;
	while (argv[i])
	{
		variable = search_variable_list(env_list, argv[i]); // search_variable_list() ESPERA COMO SEGUNDO ARGUMENTO APENAS O NOME DA VARIAVEL
printf("teste: %s", variable->str);
		if (variable) // PROCURA SE A VARIAVEL JA EXISTE E CASO SIM REDECLARAR ELA COM SEU NOVO VALOR
		{
printf("variavel: %s\n", variable->str);
		}
		else
			insert_last(env_list, copy_str(argv[i]));
		i++;
	}
}
