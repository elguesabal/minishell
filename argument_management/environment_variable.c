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

/// @brief RETORNA UM NOVO ENDERECO DE MEMORIA COPIANDO O CONTEUDO DE str ATE ENCONTRAR $ E DPS COMPLETA A STRING COM A VARIAVEL DE AMBIENTE
/// @param str STRING Q VAI TER A MEMORIA LIBERADA
/// @param new_str UMA STRING Q VAI SER COPIADA NA NOVA MEMORIA ALOCADA (UTIL PRA QUANDO QUERO UM COPIAR INFORMACOES DE VARIAVEIS DE AMBIENTE E NAO ME PREOCUPAR COM FREE NO SPLIT)
/// @return ENDERECO COM A COPIA DE new_str
char	*expand_variable(char *str, char *new_str) // SEM USO PQ ESTOU USANDO A FUNCAO copy_str()
{
	char	*copy_new;
	int	i;

	if (new_str == NULL)
	{
		copy_new = malloc(sizeof(char)); // NAO VERIFICADO
		copy_new = '\0';
		return (copy_new);
	}
	copy_new = malloc((strlen_char(str, '$') + ft_strlen(new_str) + 1) * sizeof(char));
	if (copy_new == NULL)
	{
		printf("Error: a funcao malloc() retornou NULL\n");
		// free(str); // TO USANDO free() NA FUNCAO environment_variable()
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '$')
	{
		copy_new[i] = str[i];
		i++;
	}
	// free(str); // TO USANDO free() NA FUNCAO environment_variable()
	while (*new_str)
	{
		copy_new[i] = *new_str;
		new_str++;
		i++;
	}
	copy_new[i] = '\0';
	return (copy_new);
}

char	*environment_variable(char *arg, t_str **env_list)
{
	char	*env;
	char	*arg_free;
	t_str	*no;

	if (search_dollar_sign(arg))
	{
// printf("arg + strlen_char(arg, '$'): %s\n", arg + strlen_char(arg, '$') + 1);
		no = search_variable_list(env_list, arg + strlen_char(arg, '$') + 1);
// printf("no: %s\n", no->str);
		if (no == NULL)
			env = NULL;
		else
			env = skip_c(no->str, '=');
		arg_free = arg;
		if (env)
			arg = expand_variable(arg, env + 1); // arg = copy_str(env + 1);
		else
		{
			arg = malloc(sizeof(char));
			*arg = '\0';
		}
// if (env == NULL)
// 	printf("true: %s\n", arg);
		free(arg_free);
	}
	return (arg);
}
