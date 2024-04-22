#include "../minishell.h"

/// @brief PROCURA UMA ESTRING NO COMECO DE OUTRA LEVANADO EM CONSIDERACAO O FINAL DA COMPARACAO
/// @param s1 STRING A SER COMPARADA
/// @param s2 STRING A SER COMPARADA
/// @return SE AO FINAL DA COMPARACAO TENHA '\0' em s1 e '=' em s2 RETORNA 1 EXEMPLO: "PWD", "PWD=/home/jose/programacao/minishell"
int	compare_variable(char *s1, char *s2)
{
	int			i;

	if (s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '=' && s2[i] == '\0')
		return (1);
	else
		return (0);
}

/// @brief PROCURA UMA ESTRING (VARIAVEL DE AMBIENTE) DENTRO DE UMA LISTA ENCADEADA
/// @param no LISTA A SER PERCORRIDA
/// @param s2 STRING A SER COMPARADA
/// @return RETORNA A STRING CASO ENCONTRE A VARIAVEL
/// @return SE NAO ENCONTRAR A VARIAVEL RETORNA NULL
char	*search_variable_list(t_str **no, char *str)
{
	t_str	*assist;

	assist = *no;
	while (assist)
	{
		if (compare_variable(assist->str, str))
			return (assist->str);
		assist = assist->next;
	}
	return (NULL);
}

// char	**export_variable(char **env, char *str)
// {

// CONTAR O TAMANHO DO ANTIGO PONTEIRO PARA PONTEIRO
// CRIAR UM NOVO PONTEIRO PARA ARMAZENAR TODAS AS VARIAVEIS DE AMBIENTE
// DAR FREE NO PONTEIRO QUE GUARDA TODAS AS STRINGS
// SALVAR TODOS AS ANTIGAS VARIAVEIS + A NOVA
// RETORNAR ESSE NOVO ENDERECO

// }

void	export(char **argv, char **env, t_str **env_list)
{
(void)env;

	char	*return_env;

	return_env = search_variable_list(env_list, argv[1]);
// printf("aaaaaa: %s\n", return_env);
	if (return_env)
	{
// printf("aaaaaa: %s\n", return_env);
		export_variable();
	}
}
