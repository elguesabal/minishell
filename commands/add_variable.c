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

/// @brief RETORNA UMA COPIA DO NOME DA VARIAVEL DE AMBIENTE (ALOCA MEMORIA E COPIA TUDO ANTES DO '=')
/// @param str STRING A SER ESTRAIDA O NOME DA VARIAVEL
/// @return RETORNA UM NOVO ENDERECO COM O NOME DA VARIAVEL
char	*copy_name_variable(char *str)
{
	char	*name;
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '=')
		i++;
	name = malloc((i + 1) * sizeof(char));
	if (name == NULL)
		return (NULL);
	name[i] = '\0';
	while (i)
	{
		i--;
		name[i] = str[i];
	}
	return (name);
}


/// @brief COMPARA O ENDERECO DE MEMORIA old_variable COM TODOS OS ENDERECOS DE env CASO ENCONTRE O ENDERECO DE old_variable DENTRO DE env A FUNCAO TROCA O ANTIGO ENDERECO POR new_variable
/// @param old_variable ANTIGO ENDERECO DE MEMORIA A SER SUBSTITUIDO
/// @param new_variable NOVO ENDERECO DE MEMORIA A SUBSTITUIR
/// @param env ARRAY DE ENDERECOS DE MEMORIA
void	swap_variable_array(char *old_variable, char *new_variable, char **env)
{
	int	i;

	if (old_variable == NULL)
		return ;
	i = 0;
	while (env[i])
	{
		if (env[i] == old_variable)
		{
			env[i] = new_variable;
			return ;
		}
		i++;
	}
}


void	add_variable(char **argv, char **env, t_str **env_list)
{
	int	i;
	char	*name_variable;
	char	*new_variable;
	t_str	*no;

	i = 0;
	while (argv[i])
	{
		name_variable = copy_name_variable(argv[i]);
		no = search_variable_list(env_list, name_variable); // search_variable_list() ESPERA COMO SEGUNDO ARGUMENTO APENAS O NOME DA VARIAVEL
		free(name_variable);
		if (no) // PROCURA SE A VARIAVEL JA EXISTE E CASO SIM REDECLARAR ELA COM SEU NOVO VALOR
		{
			new_variable = copy_str(argv[i]);
			swap_variable_array(no->str, new_variable, env);
			free(no->str);
			no->str = new_variable;
		}
		else
			insert_last(env_list, copy_str(argv[i]));
		i++;
	}
}
