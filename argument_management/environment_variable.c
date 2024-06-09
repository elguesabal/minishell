#include "../minishell.h"

/// @brief PROCURA SE A O SIMBULO $ Q INIDICA VARIAVEL DE AMBIENTE
/// @param str STRING QUE IRAR PROCURAR $
/// @return RETORNA 1 SE OUVER $ E ALGO APOS ISSO EXEMPLO: "teste$PATH"
/// @return RETORNA 0 SE NAO OUVER $ OU SE NAO OUVER MAIS NADA APOS $ EXEMPLO: "teste" OU "teste$"
int	search_dollar_sign(char *str)
{
	while (*str)
	{
		if (*str == '$' && str[1])
			return (1);
		str++;
	}
	return (0);
}

/// @brief RETORNA O TAMANHO QUE A STRING str DEVERIA TER CASO AS VARIAVEIS DE AMBIENTE FOSSEM EXPANDIDAS
/// @param str STRING Q VAI SR CONTADA O TAMANHO CASO EXPANDA AS VARIAVEIS DE AMBIENTE
/// @param env_list LISTA ENCADEADA COM TODAS AS VARIAVEIS DE AMBIENTE
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM O TAMANHO CORRETO
char	*malloc_variable(char *str, t_str **env_list)
{
	char	*copy_new;

	if (str == NULL)
	{
		copy_new = malloc(sizeof(char));
		copy_new = '\0';
		return (copy_new);
	}
	copy_new = malloc((len_all_variable(str, env_list) + 1) * sizeof(char));
	if (copy_new == NULL)
		printf("Error: a funcao malloc() retornou NULL\n");
	return (copy_new);
}

/// @brief RETORNA UM NOVO ENDERECO DE MEMORIA COPIANDO O CONTEUDO DE str ATE E SUBISTITUINDO $VARIAVEL POR SEU VALOR
/// @param str STRING Q VAI TER AS VARIAVEIS ESPANDIDAS
/// @param env_list LISTA ENCADEADA COM TODAS AS VARIAVEIS DE AMBIENTE
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM A VARIAVEL JA EXPANDIDA
char	*expand_variable(char *str, t_str **env_list)
{
	char	*copy_new;
	int	i;
	t_str	*no;
	char	*variable;

	copy_new = malloc_variable(str, env_list);
	if (copy_new == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str == '$')
		{
			no = search_variable_list(env_list, str + 1);
			if (no)
			{
				variable = skip_c(no->str, '=') + 1;
				while (*variable)
				{
					copy_new[i] = *variable;
					variable++;
					i++;
				}
			}
			if (*str == '$' && *(str + 1) == '?')
				str++;
			else
			{
				while (*(str + 1) && ((*(str + 1) >= '0' && *(str + 1) <= '9') || (*(str + 1) >= 'A' && *(str + 1) <= 'Z') || (*(str + 1) >= 'a' && *(str + 1) <= 'z') || *(str + 1) == '_'))
					str++;
			}
		}
		else if (++i)
			copy_new[i - 1] = *str;
		str++;
	}
	copy_new[i] = '\0';
	return (copy_new);
}

char	*environment_variable(char *arg, t_str **env_list)
{
	char	*arg_free;
	t_str	*no;
	int	i;

	if (search_dollar_sign(arg))
	{
		no = search_variable_list(env_list, arg + strlen_char(arg, '$') + 1);
		arg_free = arg;
		if (no)
			arg = expand_variable(arg, env_list);
		else
		{
			arg = malloc((strlen_char(arg, '$') + 1) * sizeof(char));
			i = 0;
			while (arg_free[i] && arg_free[i] != '$')
			{
				arg[i] = arg_free[i];
				i++;
			}
			arg[i] = '\0';
		}
		free(arg_free);
	}
	return (arg);
}
